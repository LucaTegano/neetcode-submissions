class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, double>> cars(n);//position,time
        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        /*Ordiniamo gli indici in base alla posizione delle auto in modo DECRESCENTE
        Usiamo una lambda cortissima: ordina per chi è più vicino al target
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return position[i] > position[j];
        });
        */

        // Ordina in modo decrescente per posizione (dalla più vicina al traguardo a quella più
        // lontana)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double max_time = 0.0;

        for (int i = 0; i < n; ++i) {
            if (cars[i].second > max_time) {
                fleets++;
                max_time =
                    cars[i].second;  // Questa auto che va nella fleet successiva, più lenta e fa da "tappo" per quelle dietro
            }
        }

        return fleets;
    }
};