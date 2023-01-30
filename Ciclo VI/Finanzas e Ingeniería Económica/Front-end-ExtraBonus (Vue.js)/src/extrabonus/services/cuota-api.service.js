import http from "../../core/services/http-common";

export class CuotaApiService {
    getAll() {
        return http.get("/dues");
    }

    getByBondId(id) {
        return http.get(`/BondsAndDues/${id}/dues`);
    }

    create(data) {
        return http.post("/dues", data);
    }

    update(id, data) {
        return http.put(`/dues/${id}`, data);
    }

    delete(id) {
        return http.delete(`/dues/${id}`);
    }

}