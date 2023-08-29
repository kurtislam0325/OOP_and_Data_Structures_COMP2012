#include "Boar.h"
#include "StrayDog.h"
#include "TherapyDog.h"

int main() {
    TherapyDog tdog{"Coffee", "UST", "full-time"};
    Boar boar{"Bob", "UST"};
    StrayDog sdog1{"Doge", "UST", "yellow"};
    StrayDog sdog2{"Dollar", "UST", "brown"};

//  TODO: Complete the main function
    tdog.go_to("TowerB");
    boar.go_to("GlobalGraduateTower");
    sdog1.go_to("GlobalGraduateTower");
    sdog2.go_to("TowerB");
    tdog.smile();
    
    if (boar.get_location() == sdog1.get_location()) {
        sdog1.bark_to_boar();
        boar.go_to("TowerB");
    }
    
    if (boar.get_location() == "TowerB") {
        boar.bite_package();
    }

    if (boar.get_location() == sdog2.get_location()) {
        sdog2.bark_to_boar();
    }  

    return 0;
}
