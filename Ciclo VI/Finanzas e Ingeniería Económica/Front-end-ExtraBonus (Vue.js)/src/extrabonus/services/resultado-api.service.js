import http from "../../core/services/http-common";

export class ResultadoApiService {
    getAll() {
        return http.get("/results");
    }

    getById(id) {
        return http.get(`/results/${id}`);
    }

    getByBondId(id) {
        return http.get(`/BondsAnsResults/${id}/results`);
    }

    create(data) {
        return http.post("/results", data);
    }

    update(id, data) {
        return http.put(`/results/${id}`, data);
    }

    delete(id) {
        return http.delete(`/results/${id}`);
    }

}