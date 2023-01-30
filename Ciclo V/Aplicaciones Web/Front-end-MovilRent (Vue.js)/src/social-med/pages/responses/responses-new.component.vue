
<template>
  <pv-card class="card">
    <template #content>
    <h1>{{ title }}</h1>
    <p>Por: {{ author }}</p>
    <p class="description">{{ description }}</p>


      <div class="card">
        <div class="flex flex-row flex-wrap card-container blue-container">
          <div class="flex align-items-center justify-content-center"><p>{{ promval }}</p></div>
          <div class="flex align-items-center justify-content-center"><pv-rating :modelValue="1" :readonly="true" :stars="1" :cancel="false" ></pv-rating></div>
          <div class="flex align-items-center justify-content-center w-10rem m-2"><pv-rating v-model="val" @change="postRating"/></div>
          <div class="flex align-items-center justify-content-center"><h3 class="value-temp">{{val}}</h3></div>

        </div>
      </div>

      <div class="grid">
        <div class="col-4">
          <h2>Comments: ({{ comments.length }})</h2></div>
        <div class="col-4 col-offset-4">
          <pv-button id="answer-btn" :style="'margin-top: 0.5rem'" class="p-button-rounded p-button-raised p-button-info" label="Reply" @click="newComment" />
        </div>
      </div>

    <pv-data-table :value="comments" responsiveLayout="scroll">
      <pv-column field="author" header="Author"></pv-column>
      <pv-column field="content" header="Comment" style="text-align: justify"/>
      <pv-column field="date" header="Date" style="text-align: justify"/>
    </pv-data-table>
    </template>
  </pv-card>
  <pv-dialog
      v-model:visible="commentDialog"
      :style="{ width: '800px' }"
      header="Write a comment"
      :modal="true"
      class="p-fluid"
  >
    <h2 class="field">
        <span class="p-float-label">
          {{ title }}
        </span>
    </h2>
    <div class="field">
        <span class="p-float-label">
          Por: {{ author }}
        </span>
    </div>
    <div class="field">
        <span class="text-justify p-float-label">
          {{ description }}
        </span>
    </div>
    <div class="field">
        <span class="p-float-label">
          <pv-textarea
              id="content"
              v-model="comment.content"
              required="true"
              :class="{ 'p-invalid': submitted && !comment.content }"
              :style="'margin-top:1rem'"
              :autoResize="true"
              rows="8"
              cols="2"
          />
          <label for="content" :style="'margin-top:0.50rem'">Write your comment here</label>
          <small class="p-error" v-if="submitted && !comment.content"
          >Comment is required.</small>
        </span>
    </div>
    <template #footer>
      <pv-button
          label="Publish"
          class="p-button-text"
          icon="pi pi-send"
          @click="postComment"
      />
    </template>
  </pv-dialog>
</template>

<script>
import { CommentApiService } from "../../services/comment-api.service";
import { UserApiService } from "../../services/user-api.service";
import { ForumApiService } from "../../services/forum-api.service";
import { RatingApiService } from "../../services/rating-api.service";
import { StorageService } from "../../../core/services/storage.service";

export default {
  name: "responses-new.component",
  data() {
    return {
      commentsApi: null,
      usersApi: null,
      forumsApi: null,
      ratingApi: null,
      storage: null,
      title: "",
      author: "",
      description: "",
      vals: {},
      promval: 0,
      commentDialog: false,
      comments: [],
      comment: {},
      errors: {},
      isValDisabled: false,
      isDialogVisible: false,
      users: {},
      fecha: null,
      rating: {},
      ratings: {},
      submitted: false,
      val: 0,
      forum: null
    };
  },
  created() {
    this.fecha = new Date();
    this.storage = new StorageService();
    this.commentsApi = new CommentApiService();
    this.usersApi = new UserApiService();
    this.forumsApi = new ForumApiService();
    this.ratingApi = new RatingApiService();
    this.title = this.$route.params.title;
    this.description = this.$route.params.content;
    this.getEntryAuthor(this.$route.params.userId);
    this.getCommentsToPost();
    this.getRatingsToPost();
    this.getUsers();
    this.getAverageValoration();
  },
  methods: {
    getEntryAuthor(id) {
      this.usersApi.getById(id).then((response) => {
        this.author = response.data.name + " " + response.data.lastName;
      });
    },
    getCommentsToPost() {
      this.commentsApi
        .getByForumId(this.$route.params.id)
        .then((response) => {
          this.comments = response.data;
          this.comments.forEach((comment) => {
            this.usersApi.getById(comment.userId).then((response) => {
              comment.author = response.data.name + " " + response.data.lastName;
            });
          })
          console.log(response.data);
        })
    },
    getRatingsToPost() {
      this.ratingApi.getByForumId(this.$route.params.id).then((response) => {
        this.ratings = response.data;
        console.log(response.data);
      })
    },
    getUsers() {
      this.usersApi
        .getAll()
        .then((response) => {
          console.log(typeof response.data)
          this.users = response.data;
          this.users.forEach((user) => {
            user.fullname = user.name + " " + user.lastname;
          })
        })
        .catch((error) => {
          this.errors.push(error);
          console.log(error);
        });
    },
    getAverageValoration() {
      this.ratingApi.getByForumId(this.$route.params.id).then((response) => {
        /*this.promval = 0;
        this.vals = response.data;
        if (this.vals.length !== 0) {
          this.vals.forEach((val) => {
            this.promval += val.rating.valueOf()
          })
          this.promval /= this.vals.length;
          this.promval.toFixed(2);
        }*/
        let sumval = 0;
        this.vals = response.data;
        if(this.vals.length == 0) {
          this.promval = 0
        } else {
          this.vals.forEach((rating) => {
            sumval+=rating.rate;
          });
          this.promval=sumval/this.vals.length;
        }
      });
      this.ratingApi.getByForumUserId(this.$route.params.id, 1).then((response) => {
        console.log(response)
        if (response.data.length > 0) {
          this.val = response.data[0].rating
          this.rating = response.data[0]
          console.log(this.val)
        }
      })
    },
    findIndexById(id) {
      return this.forums.findIndex((forum) => forum.id === id);
    },
    getStorableComment(displayableComment) {
      return {
        id: displayableComment.id,
        forumId: this.$route.params.id,
        userId: (displayableComment.userId = parseInt(this.storage.get("usuario"))),
        content: (displayableComment.content),
        /*date: (displayableComment.date =
          this.fecha.getDate() +
          "-" +
          (this.fecha.getMonth() + 1) +
          "-" +
          this.fecha.getFullYear()),*/
        date: new Date(),
      };

    },
    getStorableRating(displayableRating) {
      return {
        id: displayableRating.id,
        forumId: this.$route.params.id.valueOf(),
        userId: parseInt(this.storage.get("usuario")),
        rating: this.val,
      };
    },
    getDisplayableComment(comment) {
      return comment;
    },
    getDisplayableRating(rating) {
      return rating;
    },
    newComment() {
      this.commentDialog = true;
      this.submitted = false;
    },

    hideDialog() {
      this.commentDialog = false;
      this.submitted = false;
    },
    postComment() {
      this.submitted = true;
      if (this.comment.content.trim()) {
        this.comment.id = 0;
        this.comment = this.getStorableComment(this.comment);
        this.commentsApi.create(this.comment).then((response) => {
          this.usersApi.getById(this.comment.userId).then((response) => {
            this.comment.author = response.data.name + " " + response.data.lastname;
          })
          this.comment = this.getDisplayableComment(response.data);
          this.usersApi.getById(this.comment.userId).then((response) => {
            this.comment.author = response.data.name + " " + response.data.lastname;
          });
          this.comments.push(this.comment);
        });
        this.commentDialog = false;
        this.comment = {}
        console.log(this.comment);
      }
    },
    deleteRating(){
        this.ratingApi.delete(this.rating.id).then((response) => {
          this.rating = {};
          console.log(response)
          this.getAverageValoration()
        });
    },

    postRating() {
      if (this.val != null && this.val > 0) {
        if (this.rating.id) {
          this.rating = this.getStorableRating(this.rating);
          this.ratingApi.update(this.rating.id, this.rating)
        }
        else {
          this.rating = this.getStorableRating(this.rating)
          this.ratingApi.create(this.rating).then(() => {
            this.forumsApi.getById(this.rating.forumId).then((response) => {
              this.rating.rating = this.val;
              console.log(response.data);
            });
          });
        }
        this.getAverageValoration()
      }
      else if(this.rating.id){
        this.deleteRating();
      }
    }
  }
}
</script>

<style scoped>
@font-face {
  font-family: "Roboto", sans-serif;
  src: url("https://fonts.googleapis.com/css2?family=Roboto:wght@300;500&display=swap");
}
* {
  font-family: "Roboto", sans-serif;
}
i {
  color:blue;
}
h3 {
  margin-left: 10px;
  margin-top: 10px;
}
.spacer{
  margin-left: 1.2rem;
}

.description{
  text-align: justify;
}

.card{
  margin-top: 2rem;
}
.value-temp{
  margin:0;
  margin-left: 0.5rem;
}
#answer-btn {
  margin-left: 80%;
}
@media (max-width: 415px) {
  #answer-btn {
    margin-left: 70%;
  }
}
</style>
