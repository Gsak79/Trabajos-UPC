import http from "../../core/services/http-common";
export class ReportsApiService {
  getAll() {
    return http.get("/reports-bugs");
  }

  getById(id) {
    return http.get(`/reports-bugs/${id}`);
  }

  create(data) {
    return http.post("reports-bugs", data);
  }

  update(id, data) {
    return http.put(`/reports-bugs/${id}`, data);
  }

  delete(id) {
    return http.delete(`/reports-bugs/${id}`);
  }
}



