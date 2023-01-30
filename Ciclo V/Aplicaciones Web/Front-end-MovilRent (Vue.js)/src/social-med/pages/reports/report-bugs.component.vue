<template>
  <pv-toast />
  <div class="grid">
    <div class="col-12 p-fluid">
      <pv-card class="card">
        <template #content>
          <h1>Report an Error</h1>
          <div class="field">
        <span class="p-float-label">
          Insert a title
        </span>
          </div>
          <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="title"
            v-model="report.title"
            required="true"
            :autoResize="true"
            rows="2"
            cols="100"
            :class="{ 'p-invalid': submitted && !report.title }"

          />
          <small class="p-error" v-if="submitted && !report.title"
          >Title is required.</small
          >
        </span>
          </div>
          <div class="field">
        <span class="p-float-label">
          Insert a description
        </span>
          </div>
          <div class="field">
        <span class="p-float-label">
          <pv-textarea
            id="description"
            v-model="report.description"
            required="true"
            rows="10"
            cols="100"
            :autoResize="true"
            :class="{ 'p-invalid': submitted && !report.description }"
          />
          <small class="p-error" v-if="submitted && !report.description"
          >Description is required.</small
          >
        </span>
          </div>
          <div class="col-12 md:col-2 p-fluid">
            <pv-button
              label="Send Report"
              class="p-button-raised p-button-rounded"
              icon="pi pi-check"
              iconPos="right"
              @click="postReport"
            />
          </div>
        </template>
      </pv-card>
    </div>
  </div>
</template>

<script>
import { ReportsApiService } from "../../services/report-bugs-api.service";

export default {
  name: "report-bugs.component",
  data() {
    return {
      reportsApi: null,
      reports: [],
      report: {},
      title: "",
      description: "",
      submitted: false
    };
  },
  created() {
    this.reportsApi = new ReportsApiService();
    this.title = this.$route.params.title;
    this.description = this.$route.params.description;
  },
  methods: {

    getStorableReport(displayableReport) {
      return {
        id: displayableReport.id,
        title: displayableReport.title,
        description: displayableReport.description,
      };

    },

    postReport() {
      this.submitted = true;
      if(this.report.title && this.report.description) {
        this.report.id = 0;
        this.report = this.getStorableReport(this.report);
        this.reportsApi.create(this.report)
        this.submitted = false;
        this.report = {}
        this.$toast.add({
          severity: "success",
          summary: "Successful",
          detail: "Response sended",
          life: 3000,
        });
      }

    },
  }
};
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

.card{
  margin-top: 2rem;
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