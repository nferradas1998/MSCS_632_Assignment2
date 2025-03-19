class HashTable {
    constructor(size = 10) {
        this.size = size;
        this.table = new Array(size).fill(null).map(() => []);
    }

    _hash(key) {
        let hash = 0;
        for (let i = 0; i < key.length; i++) {
            hash = (hash + key.charCodeAt(i) * i) % this.size;
        }
        return hash;
    }

    insert(key, value) {
        const index = this._hash(key);
        for (let pair of this.table[index]) {
            if (pair[0] === key) {
                pair[1] = value;
                return;
            }
        }
        this.table[index].push([key, value]);
    }

    get(key) {
        const index = this._hash(key);
        for (let pair of this.table[index]) {
            if (pair[0] === key) return pair[1];
        }
        return null;
    }

    remove(key) {
        const index = this._hash(key);
        this.table[index] = this.table[index].filter(pair => pair[0] !== key);
    }
}
