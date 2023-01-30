import http from "../../core/services/http-common";

export class UsuarioApiService {
    getAll() {
        return http.get("/users");
    }

    getByUsernameAndPassword(username, password) {
        return http.get(`/users/${username}And${password}`);
    }

    getByUsername(username) {
        return http.get(`/users/=${username}`);
    }

    getById(id) {
        return http.get(`/users/${id}`);
    }

    create(data) {
        return http.post("/users", data);
    }

    update(id, data) {
        return http.put(`/users/${id}`, data);
    }

    delete(id) {
        return http.delete(`/users/${id}`);
    }

}