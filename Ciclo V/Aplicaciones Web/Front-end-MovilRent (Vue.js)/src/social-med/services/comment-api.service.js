import http from "../../core/services/http-common";

export class CommentApiService {
  getAll() {
    return http.get("/comments");
  }

  getById(id) {
    return http.get(`/comments/${id}`);
  }

  getByForumId(id) {
    return http.get(`/forums/${id}/comments/`);
  }

  create(data) {
    return http.post("/comments", data);
  }

  update(id, data) {
    return http.put(`/comments/${id}`, data);
  }

  delete(id) {
    return http.delete(`/comments/${id}`);
  }

  findByContent(content) {
    return http.get(`/comments?content=${content}`);
  }
}
