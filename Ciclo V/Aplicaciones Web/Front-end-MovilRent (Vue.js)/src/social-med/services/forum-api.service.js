import http from "../../core/services/http-common";
export class ForumApiService {
  getAll() {
    return http.get("/forums");
  }

  getById(id) {
    return http.get(`/forums/${id}`);
  }

  getByUserId(id){
    return http.get(`users/${id}/forums`);
  }

  create(data) {
    return http.post("forums", data);
  }

  update(id, data) {
    return http.put(`/forums/${id}`, data);
  }

  delete(id) {
    return http.delete(`/forums/${id}`);
  }

  findByTitle(title) {
    return http.get(`/forums?title=${title}`);
  }
}
