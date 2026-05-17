class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Coppia: {posizione, tempo_necessario_per_arrivare}
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            // Tempo = (Distanza Mancante) / Velocità
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }

        // Ordina le auto in base alla posizione iniziale (dalla più vicina al target alla più lontana)
        //sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        //    return a.first > b.first; 
        //});
        // Ordina al contrario in automatico
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        int i = 0;

        // Confronto brute force: controlla quali auto successive vengono bloccate dalla flotta corrente
        while (i < n) {
            fleets++; // Nuova flotta guidata dall'auto 'i'
            double lead_time = cars[i].second;
            int j = i + 1;
            
            // Finché le auto dietro ci mettono meno tempo (o uguale), vengono assorbite in questa flotta
            while (j < n && cars[j].second <= lead_time) {
                j++;
            }
            i = j; // Passa alla prossima auto che non viene assorbita
        }

        return fleets;
    }
};