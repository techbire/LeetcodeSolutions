class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>c ; 
    unordered_map<string,pair<string,int>>fc;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i =0;i<foods.size();i++){
            fc[foods[i]]={cuisines[i],ratings[i]};
            c[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto x = fc[food];
        string cos = x.first ;
        int rate = x.second ;
        c[cos].erase({rate,food});
        c[cos].insert({newRating,food});
        fc[food]={cos,newRating};

    }
    
    string highestRated(string cuisine) {
        auto it = c[cuisine].end();
        it--;
        int x = (*(it)).first ;
        it =  c[cuisine].lower_bound({x,"a"});
        return (*it).second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */