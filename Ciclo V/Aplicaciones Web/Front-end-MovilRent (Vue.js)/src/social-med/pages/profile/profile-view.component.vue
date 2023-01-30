<template>
  <div class="grid">
    <div class="col-2">
      <pv-card class="card">
        <template #content>
          <img :src=this.image class="doctor-image"/>
          <h3>{{ this.name + " " + this.lastName }}</h3>
          <h5> {{ this.email }}</h5>
          <h5>Speciality:</h5>
          <h6>{{ this.specialist }}</h6>
          <h5>Work place:</h5>
          <h6>{{ this.workPlace }}</h6>
          <h4>{{this.cRecommendations}} Recommendations</h4>
          <template v-if="!yourprofile">
            <template v-if="recommended">
              <pv-button label="Recommended" @click="deleteRecommend" icon="pi pi-check" iconPos="right" class="p-button-sm"/>
            </template>
            <template v-else>
              <pv-button label="Recommend" @click="setRecommend" class="p-button-sm"/>
            </template>
          </template>
          <template v-else>
              <pv-button label="Edit profile" @click="editProfile" class="p-button-sm"/>
          </template>
        </template>
      </pv-card>
    </div>
    <div class="col-10">
      <div class="grid">
        <div class="col-12">
          <pv-card class="card">
            <template #title>
              <p>Biography: </p>
            </template>
            <template #content>
              <p class="bio">{{this.biography}}</p>
            </template>
          </pv-card>
        </div>
        <div class="col-12">
          <pv-card class="card">
            <template #content>
              <pv-data-table
                ref="dt"
                :value="forums"
                dataKey="id"
                :paginator="true"
                :rows="10"
                :filters="filters"
                paginatorTemplate="FirstPageLink PrevPageLink PageLinks NextPageLink LastPageLink CurrentPageReport RowsPerPageDropdown"
                :rowsPerPageOptions="[5, 10, 15]"
                currentPageReportTemplate="Showing {first} to {last} of {totalRecords} entries"
                responsiveLayout="scroll"
              >
                <template #header>
                  <div
                    class="table-header flex flex-column md:flex-row md:justify-content-between"
                  >
                    <h5 class="mb-2 md:m-0 p-as-md-center text-xl">Entries</h5>
                    <span class="p-input-icon-left"
                    ><i class="pi pi-search" /><pv-input-text
                      v-model="filters['global'].value"
                      placeholder="Search..."
                    />
                    </span>
                  </div>
                </template>
                <pv-column
                  field="title"
                  header="Title"
                  :sortable="true"
                  style="min-width: 6rem; text-align: center;"
                ></pv-column>
                <pv-column
                  field="content"
                  header="Description"
                  :sortable="true"
                  style="max-width:30rem; white-space: nowrap;overflow: hidden; text-overflow: ellipsis;"
                ></pv-column>
                <pv-column
                  field="date"
                  header="Date"
                  :sortable="true"
                  style="width: 7.5rem;"
                ></pv-column>
                <pv-column field="rating" header="Rating" :sortable="true" style="width: 18rem">
                  <template #body="slotProps">
                    <pv-rating v-model="val" :model-value=slotProps.data.rating :cancel="false" :readonly="true"/>
                  </template>
                </pv-column>

                <pv-column :exportable="false" style="min-width: 10rem">
                  <template #body="slotProps">
                    <router-link :to="{ name: 'responses', params: slotProps.data }" style="text-decoration: none">
                      <pv-button label="View entry" class="p-button-outlined"></pv-button>
                    </router-link>
                  </template>
                </pv-column>
              </pv-data-table>
            </template>
          </pv-card>
        </div>

      </div>
    </div>
  </div>
  <pv-dialog
    v-model:visible="this.editProfileDialog"
    :style="{ width: '800px' }"
    header="Edit profile"
    :modal="true"
    class="p-fluid"
  >
    <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="name"
            v-model="profile.name"
            required="true"
            :class="{ 'p-invalid': submitted && !profile.name }"
            class="mt-3"
            :autoResize="true"
            rows="1"
            cols="1"
          />
          <label for="content" class="mt-3">Name</label>
          <small class="p-error" v-if="submitted && !profile.name"
          >Name is required.</small>
        </span>
    </div>
    <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="name"
            v-model="profile.lastName"
            required="true"
            :class="{ 'p-invalid': submitted && !profile.lastName }"
            class="mt-3"
            :autoResize="true"
            rows="1"
            cols="1"
          />
          <label for="content" class="mt-3">Lastname</label>
          <small class="p-error" v-if="submitted && !profile.lastName"
          >Lastname is required.</small>
        </span>
      <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="name"
            v-model="profile.email"
            required="false"
            class="mt-3"
            :autoResize="true"
            rows="1"
            cols="1"
          />
          <label for="content" class="mt-3">Email</label>
        </span>
      </div>

      <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="name"
            v-model="profile.specialist"
            required="true"
            :class="{ 'p-invalid': submitted && !profile.specialist }"
            class="mt-3"
            :autoResize="true"
            rows="1"
            cols="1"
          />
          <label for="content" class="mt-3">Specialist</label>
          <small class="p-error" v-if="submitted && !profile.specialist"
          >Specialist is required.</small>
        </span>
      </div>
      <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="name"
            v-model="profile.workPlace"
            required="false"
            class="mt-3"
            :autoResize="true"
            rows="1"
            cols="1"
          />
          <label for="content" class="mt-3">Work place</label>
        </span>
      </div>
      <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="name"
            v-model="profile.biography"
            required="true"
            :class="{ 'p-invalid': submitted && !profile.biography }"
            class="mt-3"
            :autoResize="true"
            rows="5"
            cols="1"
          />
          <label for="content" class="mt-3">Biography</label>
          <small class="p-error" v-if="submitted && !profile.biography"
          >Biography is required.</small>
        </span>
    </div>
    </div>
    <template #footer>
      <pv-button
        label="Update"
        class="p-button-text"
        icon="pi pi-send"
        @click="updateProfile"
      />
    </template>
  </pv-dialog>
</template>

<script>
import { RecommendationApiService } from "../../services/recommendation-api.service";
import { ForumApiService } from "../../services/forum-api.service";
import { RatingApiService } from "../../services/rating-api.service";
import { UserApiService } from "../../services/user-api.service";
import { FilterMatchMode } from "primevue/api";
import { StorageService } from "../../../core/services/storage.service";

export default {
  name: "profile-view",
  data() {
    return {
      cRecommendations: 0,
      yourprofile: false,
      recommendacionApiService: null,
      recommended: false,
      forums: [],
      forumsService: null,
      vals: {},
      filters: {},
      user: {},
      ratingService: null,
      usersService: null,
      recommendation: {},
      storage: null,
      profile: {},
      submitted: false,
      editProfileDialog: false,
      name: "",
      lastName: "",
      email: "",
      workPlace: "",
      biography: "",
      specialist: "",
      residence: "",
      phone: "",
      image: ""
    }
  },
  created() {
    this.recommendationApiService = new RecommendationApiService();
    this.storage = new StorageService()
    this.countRecommendations();
    if(this.storage.get("profile") === this.storage.get("usuario")) this.yourprofile = true

    this.forumsService = new ForumApiService();
    this.ratingService = new RatingApiService();
    this.usersService = new UserApiService();

    this.setProfile();

    this.forumsService.getByUserId(parseInt(this.storage.get("profile"))).then((response) => {
      this.forums = response.data;
      this.forums.forEach((forum) => {
        let fecha = new Date(forum.date)
        forum.date = `${fecha.getDay()}-${fecha.getMonth()}-${fecha.getFullYear()}`
        this.usersService.getById(forum.userId).then((response) => {
          forum.author = response.data.name + " " + response.data.lastName;
        });
        this.ratingService.getByForumId(forum.id).then((response) => {

          let sumval = 0;
          this.vals = response.data;
          if(this.vals.length == 0) {
            forum.rating = 0
          } else {
            this.vals.forEach((rating) => {
              sumval+=rating.rate;
            });
            forum.rating=sumval/this.vals.length;
          }

          /*let promval = 0;
          this.vals = response.data;
          if (this.vals.length === 0) {
            forum.rating = 0
          } else {
            this.vals.forEach((val) => {
              promval += val.rating.valueOf()
            })
            promval /= this.vals.length;
            forum.rating = promval.toFixed(2);
          }*/
        })
      })
      console.log(this.forums);
    });
    this.initFilters();
  },
  methods: {
    setProfile(){
      this.usersService.getById(this.storage.get("profile")).then( (response) => {
        this.profile = response.data
        this.name = response.data.name
        this.email = response.data.email
        this.lastName = response.data.lastName
        this.biography = response.data.biography
        this.specialist = response.data.specialist
        this.residence = response.data.residence
        this.phone = response.data.phone
        this.workPlace = response.data.workPlace
        this.image = response.data.image
      })
    },
    initFilters() {
      this.filters = {
        global: { value: null, matchMode: FilterMatchMode.CONTAINS },
      };
    },
    countRecommendations() {
      this.recommendationApiService.getByRecommendedUserId(this.profile.id).then((response) => {
        console.log(response.data.length)
        this.cRecommendations = response.data.length
      });
    },
    getStorableReport(displayableRecommendation) {
      return {
        id: displayableRecommendation.id,
        recommendationUserId: 1,
        recommendedUserId: this.profile.id
      };
    },
    setRecommend() {
      this.recommended = true
      this.recommendation.id = 0;
      this.recommendation = this.getStorableReport(this.recommendation);
      this.recommendationApiService.create(this.recommendation)
      this.recommendation = {}

      this.cRecommendations++;
    },
    deleteRecommend() {
      this.recommended = false
      this.recommendationApiService.getByRecommendedRecommendationUserId(this.profile.id, 1).then((response) => {
        console.log(response.data)
        console.log(response.data[0].id)
        this.recommendationApiService.delete(response.data[0].id)
      })

      this.cRecommendations--;
    },
    editProfile(){
      this.editProfileDialog = true
    },
    updateProfile(){
      this.submitted = true;
      if (this.profile.name.trim() && this.profile.lastName.trim() && this.profile.specialist.trim() && this.profile.biography.trim()) {
        this.usersService.update(this.profile.id, this.profile).then((response) => {
          this.profile = response.data
          this.name = response.data.name
          this.email = response.data.email
          this.lastName = response.data.lastName
          this.biography = response.data.biography
          this.specialist = response.data.specialist
          this.residence = response.data.residence
          this.phone = response.data.phone
          this.workPlace = response.data.workPlace
          this.image = response.data.image
        })
        this.editProfileDialog = false;
      }

    }
  }

}
</script>

<style scoped>
.doctor-profile {
  border: 1px solid var(--surface-border);
  border-color: blue;
  border-radius: 3px;
  margin: .3rem;
  text-align: center;
  padding: 2rem 0;
}
.card{
  margin-top: 1rem;
}

h4{
  font-family: Roboto, sans-serif;
  font-weight: normal;
  font-size: 12px;
  margin-top: 0px;
  margin-bottom: 1rem;
}

h5{
  font-family: Roboto, sans-serif;
  font-weight: bold;
  font-size: 12px;
  margin-bottom: 0;
}
h6{
  font-family: Roboto, sans-serif;
  font-weight: lighter;
  font-size: 12px;
  margin-top: 0px;
  margin-bottom: 1rem;
}

.p-button-sm{
  margin-top: 1rem;
}

.bio{
  margin: 0;
}
</style>
