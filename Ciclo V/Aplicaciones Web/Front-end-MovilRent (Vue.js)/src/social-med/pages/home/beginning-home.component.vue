<template>
  <pv-card class="card">
    <template #title>
      Recomended entries for you
    </template>
    <template #content>
  <pv-data-table :value="forums"  :rows=4 responsiveLayout="stack" >
    <pv-column field="author" header="Author" style="text-align: center;"></pv-column>
    <pv-column field="title" header="Title" style="text-align: center"></pv-column>
    <pv-column field="content" header="Description" style="max-width:30rem; white-space: nowrap;overflow: hidden; text-overflow: ellipsis;"></pv-column>
    <pv-column field="date" header="Publication date" style="text-align: center"></pv-column>
    <pv-column field="rating" header="Rating" style="width: 10rem">
      <template #body="slotProps">
        <pv-rating v-model="val" :model-value=slotProps.data.rating :cancel="false" :readonly="true"/>
      </template>
    </pv-column>
    <pv-column style="width: 10rem;">
      <template #body="slotProps">
        <router-link  :to="{name: 'responses', params: slotProps.data} " style="text-decoration: none">
          <pv-button label="View entry" class="p-button-outlined"></pv-button>
        </router-link>
      </template>

    </pv-column>
    <template #footer>
      <RouterLink to="/forums">
        <pv-button label="View more recommended entries" class="p-button-link" />
      </RouterLink>
    </template>

  </pv-data-table>
    </template>
  </pv-card>

  <pv-card class="card">
    <template #title>
      Recomended doctors for you
    </template>
    <template #content>
      <pv-carousel :value="users" :numVisible="3" :numScroll="1" :responsiveOptions="responsiveOptions" class="custom-carousel" :circular="true" :autoplayInterval="5000">
        <template #item="slotProps">
          <div class="doctor-profile">
              <img :src=slotProps.data.image class="doctor-image"/>
              <h3 class="doctor-name">{{ slotProps.data.fullname }}</h3>
              <h4>{{ slotProps.data.specialist}}</h4>
              <h5 class="doctor-description">{{ slotProps.data.recommendation }} Recommendations</h5>
              <h5 class="doctor-description">{{ slotProps.data.workPlace}}</h5>
              <router-link :to="{ name: 'profile', params: slotProps.data }"  style="text-decoration: none">
                <pv-button label="View profile" @click="this.storage.set('profile', slotProps.data.id)" class="p-button-outlined"></pv-button>
              </router-link>
          </div>
        </template>
      </pv-carousel>
    </template>
  </pv-card>

</template>

<script>
import { ForumApiService } from "../../services/forum-api.service";
import { UserApiService } from "../../services/user-api.service";
import { RatingApiService } from "../../services/rating-api.service";
import { StorageService } from "../../../core/services/storage.service";

export default {
  name: "beginning-home.component",
  data(){
    return{
      responsiveOptions: [
        {
          breakpoint: '1024px',
          numVisible: 2,
          numScroll: 2
        },
      ],
      storage: null,
      forums: {},
      users: {},
      forum: {},
      vals: {},
      forumsService: null,
      usersService: null,
      ratingService: null,
      user: null
    }
  },
  created() {
    this.storage = new StorageService();
    this.forumsService = new ForumApiService();
    this.usersService = new UserApiService();
    this.ratingService = new RatingApiService();
    this.forumsService.getAll().then((response) => {
      this.forums = response.data;
      this.forums.forEach( (forum) => {
        let fecha = new Date(forum.date)
        forum.date = `${fecha.getDay()}-${fecha.getMonth()}-${fecha.getFullYear()}`
        this.usersService.getById(forum.userId).then( (response) => {
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


          /*else {
          this.vals.forEach((val) => {
            promval += val.rating.valueOf()
          })
          promval /= this.vals.length;
          forum.rating = promval.toFixed(2);
          }*/
        })
      })
    })
    this.usersService.getAll().then((response) => {
      this.users = response.data;
      this.users.forEach( (user) => {
        user.fullname = user.name + " " + user.lastName;
      })
    });

  },
};
</script>

<style>
 .card{
   margin-top: 1.5rem;
 }

 .doctor-profile {
   border: 1px solid var(--surface-border);
   border-color: blue;
   border-radius: 3px;
   margin: .3rem;
   text-align: center;
   padding: 2rem 0;
 }

 .doctor-image{
   width:7rem;
   height: 7rem;
   border-radius: 50%;
   border: solid 1px #000000
 }

 .doctor-name{
   font-family: Roboto, sans-serif;
   font-size: 1.25rem;
 }

 .doctor-description{
   font-weight: lighter;
   margin: 2px;
 }

 .p-button-outlined{
   margin-top: 1.5rem;
 }

 .table-forum{
   border: solid 1px blue;
 }
</style>

