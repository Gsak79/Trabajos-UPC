<template>
  <div>
    <pv-card class="mt-3">
      <template #title>Notifications</template>
      <template #content>
        <pv-data-table
          ref="dt"
          :value="displayableNotifications"
          dataKey="id"
          :paginator="true"
          :rows="10"
          paginatorTemplate="FirstPageLink PrevPageLink PageLinks NextPageLink LastPageLink CurrentPageReport RowsPerPageDropdown"
          :rowsPerPageOptions="[5, 10, 15]"
          responsiveLayout="scroll"
          currentPageReportTemplate="Showing {first} to {last} of {totalRecords} notifications"
        >
          <template #header>
            <h2 class="m-0">New notifications ({{notifications.length}})</h2>
          </template>
          <pv-column>
            <template #body="slotProps">
              <img :src="slotProps.data.userImage" class="doctor-image"/>
            </template>
          </pv-column>
          <pv-column field="title" :sortable="false" />
          <pv-column field="userDescription" :sortable="false" />
          <pv-column>
            <template #body="slotProps">
              <div v-for="action in actionsCodesArrayFromStr(slotProps.data.actionsCodes)" :key="action">
                <template v-if="action==1">

                  <router-link  :to="'/profile/'+slotProps.data.referencesToUserId" style="text-decoration: none">
                    <pv-button  label="View profile" @click="this.storage.set('profile', slotProps.data.referencesToUserId)" style="margin: 0.7rem" class="p-button-outlined"></pv-button>
                  </router-link>
                </template>
                <template v-else-if="action==3">
                  <router-link  :to="{ name: 'responses', params: {id: 1, userId: 1} }">
                    <pv-button label="View entry" style="margin: 0.7rem" class="p-button-outlined"></pv-button>
                  </router-link>
                </template>
                <template v-else>
                </template>
              </div>
            </template>
          </pv-column>
        </pv-data-table>
      </template>
    </pv-card>
  </div>
</template>

<script>
import { NotificationApiService } from "../../services/notification-api.service";
import { UserApiService } from "../../services/user-api.service";
import { StorageService } from "../../../core/services/storage.service";

export default {
  name: "notifications-view",
  data() {
    return {
      storage: null,
      notifications: [],
      displayableNotifications: [],
      notificationsApi: new NotificationApiService(),
      usersApi: new UserApiService(),
      dataColumns: [
        { num: 1, field: "title" },
        { num: 2, field: "userId" },
      ]
    };
  },
  created() {
    this.storage = new StorageService()
    this.getAllNotifications();
  },
  methods: {
    getAllNotifications() {
      this.notificationsApi.getAll().then((response) => {
        this.notifications = response.data;
        console.log(this.notifications.length);
        this.getDisplayableNotifications();
      });
    },
    getDisplayableNotifications() {
      this.notifications.forEach((notification) => {
        this.usersApi.getById(notification.referencesToUserId).then((response) => {
          this.displayableNotifications.push({
            id: notification.id,
            userImage: "../media/" + response.data.image,
            title: `${response.data.name} ${response.data.lastName} ${notification.title}`,
            userDescription: `${response.data.specialist}\n${response.data.workPlace}`,
            actionsCodes: notification.actionsCodes,
            referencesToUserId: notification.referencesToUserId
          });
        });
      });
      console.log(this.displayableNotifications);
    },
    actionsCodesArrayFromStr(numString) {
      let numArray=[];
      let num = "";
      for(let i=0;i<numString.length; ++i) {
        if (numString.charAt(i)==',' || i==numString.length-1)
        {
          numArray.push(Number(num));
          num = "";
        }
        else
          num+=numString.charAt(i);
      }
      return numArray;
    },
  },
};
</script>

<style scoped>
.doctor-image{
  width:7rem;
  height: 7rem;
  border-radius: 50%;
  border: solid 1px #000000
}
</style>
