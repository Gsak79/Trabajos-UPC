<template>
  <div>
    <div class="card">
      <pv-toolbar class="mb-4">
        <template #start>
          <pv-button
            label="Create entry"
            icon="pi pi-plus"
            class="p-button-success mr-2"
            @click="openNew"
          />
          <pv-button
            label="Delete entry"
            icon="pi pi-trash"
            class="p-button-danger"
            @click="confirmDeleteSelected"
            :disabled="!selectedForums || !selectedForums.length"
          />
        </template>
        <template #end> </template>
      </pv-toolbar>
      <pv-card>
        <template #content>
          <pv-data-table
            ref="dt"
            :value="forums"
            v-model:selection="selectedForums"
            dataKey="id"
            :paginator="true"
            :rows="10"
            :filters="filters"
            paginatorTemplate="FirstPageLink PrevPageLink PageLinks NextPageLink LastPageLink CurrentPageReport RowsPerPageDropdown"
            :rowsPerPageOptions="[5, 10, 15]"
            currentPageReportTemplate="Showing {first} to {last} of {totalRecords} Entries"
            responsiveLayout="scroll"
          >
            <template #header>
              <div
                class="table-header flex flex-column md:flex-row md:justify-content-between"
              >
                <h5 class="mb-2 md:m-0 p-as-md-center text-xl">
                  Manage my entries
                </h5>
                <span class="p-input-icon-left"
                  ><i class="pi pi-search" /><pv-input-text
                    v-model="filters['global'].value"
                    placeholder="Search..."
                  />
                </span>
              </div>
            </template>
            <pv-column
              selectionMode="multiple"
              style="width: 3rem"
              :exportable="false"
            ></pv-column>
            <pv-column
              field="title"
              header="Title"
              :sortable="true"
              style="min-width: 6rem; text-align: center"
            ></pv-column>
            <pv-column
              field="content"
              header="Description"
              :sortable="true"
              style="
                max-width: 30rem;
                white-space: nowrap;
                overflow: hidden;
                text-overflow: ellipsis;
              "
            ></pv-column>
            <pv-column
              field="date"
              header="Date"
              :sortable="true"
              style="width: 8rem"
            ></pv-column>
            <pv-column
              field="rating"
              header="Rating"
              :sortable="true"
              style="width: 10rem"
            >
              <template #body="slotProps">
                <pv-rating
                  v-model="val"
                  :model-value="slotProps.data.rating"
                  :cancel="false"
                  :readonly="true"
                />
              </template>
            </pv-column>
            <pv-column
              :exportable="false"
              header="Actions"
              style="min-width: 6rem"
            >
              <template #body="slotProps">
                <pv-button
                  icon="pi pi-pencil"
                  class="p-button-text p-button-rounded"
                  @click="editForum(slotProps.data)"
                />
                <pv-button
                  icon="pi pi-trash"
                  class="p-button-text p-button-rounded"
                  @click="confirmDeleteForum(slotProps.data)"
                />
              </template>
            </pv-column>
            <pv-column :exportable="false" style="min-width: 10rem">
              <template #body="slotProps">
                <router-link
                  :to="{ name: 'responses', params: slotProps.data }"
                  style="text-decoration: none"
                >
                  <pv-button
                    label="View entry"
                    class="p-button-outlined"
                  ></pv-button>
                </router-link>
              </template>
            </pv-column>
          </pv-data-table>
        </template>
      </pv-card>
    </div>
    <pv-dialog
      v-model:visible="forumDialog"
      :style="{ width: '40vw' }"
      header=""
      :modal="true"
      class="p-fluid"
    >
      <div class="field" >
        <span class="p-float-label" :style="'margin-top:1.5rem'">
          <pv-textarea
            type="text"
            id="title"
            v-model.trim="forum.title"
            required="true"
            rows="1"
            cols="1"
            autofocus
            :autoResize="true"
            :class="{ 'p-invalid': submitted && !forum.title }"
          />
          <label for="title" :style="'margin-top:-0.2rem'">Title </label>
          <small class="p-error" v-if="submitted && !forum.title"
            >Title is required.</small
          >
        </span>
      </div>
      <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="content"
            :autoResize="true"
            v-model="forum.content"
            required="true"
            rows="5"
            cols="2"
            :style="'margin-top:1rem'"
            :class="{ 'p-invalid': submitted && !forum.content }"
          />
          <label for="content" :style="'margin-top:0.50rem'">Description</label>
          <small class="p-error" v-if="submitted && !forum.content"
          >Description is required.</small
          >
        </span>
      </div>
      <template #footer>
        <pv-button
          label="Cancel"
          icon="pi pi-times"
          class="p-button-text"
          @click="hideDialog"
        />
        <pv-button
          label="Save"
          icon="pi pi-check"
          class="p-button-text"
          @click="saveForum"
        />
      </template>
    </pv-dialog>
    <pv-dialog
      v-model:visible="deleteForumDialog"
      :style="{ width: '450px' }"
      header="Confirm"
      :modal="true"
    >
      <div class="confirmation-content">
        <i class="pi pi-exclamation-triangle mr-3" style="font-size: 2rem" />
        <span v-if="forum"
          >Are you sure you want to delete <b>{{ forum.title }}</b></span
        >
      </div>
      <template #footer>
        <pv-button
          label="No"
          icon="pi pi-times"
          class="p-button-text"
          @click="deleteForumDialog = false"
        />
        <pv-button
          label="Yes"
          icon="pi pi-check"
          class="p-button-text"
          @click="deleteForum"
        />
      </template>
    </pv-dialog>
    <pv-dialog
      v-model:visible="deleteForumsDialog"
      :style="{ width: '450px' }"
      header="Confirm"
      :modal="true"
    >
      <div class="confirmation-content">
        <i class="pi pi-exclamation-triangle mr-3" style="font-size: 2rem" />
        <span v-if="selectedForums"
          >Are you sure you want to delete the selected Entries?</span
        >
      </div>
      <template #footer>
        <pv-button
          label="No"
          icon="pi pi-times"
          class="p-button-text"
          @click="deleteForumsDialog = false"
        />
        <pv-button
          label="Yes"
          icon="pi pi-check"
          class="p-button-text"
          @click="deleteSelectedForums"
        />
      </template>
    </pv-dialog>
  </div>
</template>

<script>
import { FilterMatchMode } from "primevue/api";
import { ForumApiService } from "../../services/forum-api.service";
import { RatingApiService } from "../../services/rating-api.service";
import { StorageService } from "../../../core/services/storage.service";

export default {
  name: "entrances-new.component",
  data() {
    return {
      forums: [],
      forumDialog: false,
      deleteForumsDialog: false,
      deleteForumDialog: false,
      forum: {},
      selectedForums: null,
      filters: {},
      vasl: {},
      submitted: false,
      forumsService: null,
      storage: null,
      ratingService: null,
      fecha: null,
    };
  },
  created() {
    this.fecha = new Date();
    this.storage = new StorageService();
    this.forumsService = new ForumApiService();
    this.ratingService = new RatingApiService();
    this.forumsService.getByUserId(parseInt(this.storage.get("usuario"))).then((response) => {
      this.forums = response.data;
      this.forums.forEach((forum) => {
        let fecha = new Date(forum.date)
        forum.date = `${fecha.getDay()}-${fecha.getMonth()}-${fecha.getFullYear()}`
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
            forum.rating = 0;
          } else {
            this.vals.forEach((val) => {
              promval += val.rating.valueOf();
            });
            promval /= this.vals.length;
            forum.rating = promval.toFixed(2);
          }*/
        });
      });
      console.log(this.forums);
    });
    this.initFilters();
  },
  methods: {
    getStorableForum(displayableForum) {
      return {
        id: displayableForum.id,
        title: displayableForum.title,
        content: displayableForum.content,
        date: new Date(Date.now()),
        userId: (displayableForum.userId = parseInt(this.storage.get("usuario"))),
      };
    },
    initFilters() {
      this.filters = {
        global: { value: null, matchMode: FilterMatchMode.CONTAINS },
      };
    },
    findIndexById(id) {
      return this.forums.findIndex((forum) => forum.id === id);
    },
    openNew() {
      this.forum = {};
      this.submitted = false;
      this.forumDialog = true;
    },
    hideDialog() {
      this.forumDialog = false;
      this.submitted = false;
    },
    getDisplayableForum(forum) {
      return forum;
    },
    saveForum() {
      this.submitted = true;
      if (this.forum.title.trim() && this.forum.content.trim()) {
        if (this.forum.id) {
          this.forum = this.getStorableForum(this.forum);
          this.forumsService
            .update(this.forum.id, this.forum)
            .then((response) => {
              this.forums[this.findIndexById(response.data.id)] =
                this.getDisplayableForum(response.data);
              this.$toast.add({
                severity: "success",
                summary: "Successful",
                detail: "Entry Updated",
                life: 3000,
              });
              console.log(response);
            });
        } else {
          this.forum.id = 0;
          this.forum = this.getStorableForum(this.forum);
          this.forumsService.create(this.forum).then((response) => {
            this.forum = this.getDisplayableForum(response.data);
            let fecha = new Date(this.forum.date)
            this.forum.date = `${fecha.getDay()}-${fecha.getMonth()}-${fecha.getFullYear()}`
            this.forums.push(this.forum);
            this.$toast.add({
              severity: "success",
              summary: "Successful",
              detail: "Entry Created",
              life: 3000,
            });
            console.log(response);
          });
        }
        this.forumDialog = false;
        this.forum = {};
      }
    },
    editForum(forum) {
      this.forum = { ...forum };
      this.forumDialog = true;
    },
    confirmDeleteForum(forum) {
      this.forum = forum;
      this.deleteForumDialog = true;
    },
    deleteForum() {
      this.forumsService.delete(this.forum.id).then((response) => {
        this.forums = this.forums.filter((f) => f.id !== this.forum.id);
        this.deleteForumDialog = false;
        this.forum = {};
        this.$toast.add({
          severity: "success",
          summary: "Successful",
          detail: "Entry Deleted",
          life: 3000,
        });
        console.log(response);
      });
    },
    confirmDeleteSelected() {
      this.deleteForumsDialog = true;
    },
    deleteSelectedForums() {
      this.selectedForums.forEach((forum) => {
        this.forumsService.delete(forum.id).then((response) => {
          this.forums = this.forums.filter((f) => f.id !== forum.id);
          console.log(response);
        });
      });
      this.deleteForumsDialog = false;
      this.selectedForums = null;
    },
  },
};
</script>

<style scoped>
.card {
  margin-top: 1.5rem;
}
</style>
