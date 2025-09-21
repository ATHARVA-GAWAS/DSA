class MovieRentingSystem {
    unordered_map<int, set<pair<int,int>>> shoplist;   //{movie, {price, shop}}
    map<pair<int,int>, int> movieShopPrice;  //{price for {movie, shop}} 
    set<vector<int>> rented;   //{price, shop, movie} 
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto it:entries){
            int shop=it[0];
            int movie=it[1];
            int price=it[2];

            shoplist[movie].insert({price,shop});

            movieShopPrice[{movie,shop}]=price;
        }
    }
    
    vector<int> search(int movie) {
        int cnt=0;

        vector<int> shops;

        for(auto it:shoplist[movie]){
            int price=it.first;
            int shop=it.second;

            shops.push_back(shop);

            cnt++;

            if(cnt==5){
                break;
            }
        }

        return shops;
    }
    
    void rent(int shop, int movie) {
        int price=movieShopPrice[{movie,shop}];

        shoplist[movie].erase({price,shop});

        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price=movieShopPrice[{movie,shop}];

        rented.erase({price, shop, movie});

        shoplist[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        int cnt=0;

        vector<vector<int>> res;

        for(auto it:rented){
            int price=it[0];
            int shop=it[1];
            int movie=it[2];

            res.push_back({shop,movie});

            cnt++;

            if(cnt==5){
                break;
            }
        }

        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */