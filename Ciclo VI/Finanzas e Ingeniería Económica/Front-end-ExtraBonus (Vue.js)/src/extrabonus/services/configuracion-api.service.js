import http from "../../core/services/http-common";

export class ConfiguracionApiService {
  getByUserId(id) {
    return http.get(`/users/${id}/configurations`);
  }

  create(data) {
    return http.post("/configurations", data);
  }

  update(id, data) {
    return http.put(`/configurations/${id}`, data);
  }
}
