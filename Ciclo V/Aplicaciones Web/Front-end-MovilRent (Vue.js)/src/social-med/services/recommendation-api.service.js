import http from "../../core/services/http-common";

export class RecommendationApiService {
  getAll() {
    return http.get("/recommendations");
  }

  getByRecommendedUserId(id) {
    return http.get(`/recommendations?recommendedUserId=${id}`);
  }

  getByRecommendedRecommendationUserId(recommendedId, recommendationId){
    return http.get(`/recommendations?recommendedUserId=${recommendedId}&recommendationUserId=${recommendationId}`)
  }

  create(data) {
    return http.post("/recommendations", data);
  }

  update(id, data) {
    return http.put(`/recommendations/${id}`, data);
  }

  delete(id) {
    return http.delete(`/recommendations/${id}`);
  }
}
