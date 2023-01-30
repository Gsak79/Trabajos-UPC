import http from "../../core/services/http-common";
export class NotificationApiService {
  getAll() {
    return http.get("/notifications");
  }

  getById(id) {
    return http.get(`/notifications/${id}`);
  }

  create(data) {
    return http.post("/notifications", data);
  }

  update(id, data) {
    return http.put(`/notifications/${id}`, data);
  }

  delete(id) {
    return http.delete(`/notifications/${id}`);
  }
}