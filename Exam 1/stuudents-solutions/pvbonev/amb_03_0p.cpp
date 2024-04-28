#include <bits/stdc++.h>

int n,k;

struct Apartment
{
    int distance;
    int index;

    Apartment(int dist, int ind): distance(dist), index(ind) {}
};

int minMaxDistance(int n, int k, std::vector<int> distances)
{
    std::vector<Apartment> sortedApartments;
    for(std::size_t i = 0; i < n; ++i)
    {
        sortedApartments.push_back(Apartment(distances[i],i));
    }

    std::sort(sortedApartments.begin(),sortedApartments.end(),
        [](const Apartment& a, const Apartment& b)
        {
            return a.distance < b.distance;
        });
    
    std::vector<int> minDistances(n,INT_MAX);

    for(std::size_t i = 0; i < k; ++i)
    {
        Apartment apartment = sortedApartments.back();
        sortedApartments.pop_back();
        minDistances[apartment.index] = 0;
        for(std::size_t j = apartment.index + 1; j < n; ++j)
        {
            minDistances[i] = std::min(minDistances[i], distances[i - 1] + minDistances[apartment.index]);
        }
    }

    return *max_element(minDistances.begin(),minDistances.end());    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>n>>k;

    std::vector<int> distances(n - 1);
    for(std::size_t i = 0; i < n;++i)
    {
        std::cin>>distances[i];
    }

    std::cout<<minMaxDistance(n,k,distances);


}