#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> Lotto(int numspots, int numselect){
    std::vector<int> lotterycard;
    for(int i=0;i<numspots;i++){
       lotterycard.push_back(i);
    }
    random_shuffle(lotterycard.begin(), lotterycard.end());
    std::vector<int> result(numselect);
    copy(lotterycard.begin(), lotterycard.begin()+numselect, result.begin());
    sort(result.begin(), result.end());
    return result;
}

int main(){
    std::vector<int> winners;
    winners = Lotto(51,6);
    std::ostream_iterator<int, char> out_iter(std::cout, " ");
    copy(winners.begin(), winners.end(), out_iter);
    std::cout << std::endl;
    return 0;
}

