import http from "../../core/services/http-common";

export class BonoApiService {
    getAll() {
        return http.get("/bonds");
    }

    getByUserId(id){
        return http.get(`/UsersAndBonds/${id}/bonds`);
    }

    getById(id) {
        return http.get(`/bonds/${id}`);
    }

    create(data) {
        return http.post("/bonds", data);
    }

    update(id, data) {
        return http.put(`/bonds/${id}`, data);
    }

    delete(id) {
        return http.delete(`/bonds/${id}`);
    }

}