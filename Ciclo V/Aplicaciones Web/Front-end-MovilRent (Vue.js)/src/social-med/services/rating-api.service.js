import http from "../../core/services/http-common";

export class RatingApiService {
  getAll() {
    return http.get("/ratings");
  }

  getByForumId(id) {
    return http.get(`/forums/${id}/ratings`);
  }

  getByForumUserId(idForum, idUser) {
    return http.get(`ratings?forumId=${idForum}&userId=${idUser}`);
  }

  create(data) {
    return http.post("/ratings", data);
  }

  update(id, data) {
    return http.put(`/ratings/${id}`, data);
  }

  delete(id) {
    return http.delete(`/ratings/${id}`);
  }
}
