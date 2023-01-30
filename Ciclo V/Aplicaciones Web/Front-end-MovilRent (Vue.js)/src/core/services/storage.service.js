export class StorageService {
  constructor() {}

  set(key, data) {
    try {
      localStorage.setItem(key, JSON.stringify(data));
    } catch (e) {
      console.log(e);
    }
  }
  get(key) {
    return localStorage.getItem(key);
  }
}