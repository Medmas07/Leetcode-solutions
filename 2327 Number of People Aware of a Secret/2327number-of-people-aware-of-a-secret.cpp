class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> newPeople(n + 1, 0);
        newPeople[1] = 1;

        long long sharing = 0;  // Nombre de gens capables de partager
        long long total = 0;    // Total de personnes se souvenant du secret

        for (int day = 2; day <= n; ++day) {
            // Les gens qui peuvent commencer à partager
            if (day - delay >= 1) {
                sharing = (sharing + newPeople[day - delay]) % MOD;
            }

            // Ceux qui oublient aujourd'hui
            if (day - forget >= 1) {
                sharing = (sharing - newPeople[day - forget] + MOD) % MOD;
            }

            newPeople[day] = sharing;
        }

        // Somme des personnes qui n'ont pas oublié le secret à la fin
        for (int day = n - forget + 1; day <= n; ++day) {
            total = (total + newPeople[day]) % MOD;
        }

        return total;
    }
};
