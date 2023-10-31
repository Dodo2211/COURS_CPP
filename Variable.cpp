/*/// Notion de type//// 
     <type> ma_variable; // ou <type> doit etre un type c++
*/

/*///Un mot sur le nommage des variables///

    * un nom de variable est constitué de lettres, chiffres et du symbole underscore
    * le premier caractère est forcément une lettre
    * un nom de variable ne peut comporter aucun espace

     int accentuée = 10; // accent possible depuis C++11
     double σ = K * ɛ ; // lettre grec egalement possible
     
    * preferable de ne pas utilisé d'accents
*/

/*// Type intégraux///
    // ENTIERS//
        int un_int; //32 bits
        unsigned int un_uint; // int sur 32 bits non signés
        short int un_sint; // int sur 16 bits
*/
/*      //Code pour conaitres les valeurs limites
            #include <iostream>
            #include <limits>
            int main(){
                std::cout << "short int: " << std::numeric_limits<short int>::min() << " -> " 
                                        << std::numeric_limits<short int>::max() << std::endl;
                std::cout << "int: " << std::numeric_limits<int>::min() << " -> " 
                                        << std::numeric_limits<int>::max() << std::endl;
                std::cout << "unsigned int: " << std::numeric_limits<unsigned int>::min() << " -> " 
                                        << std::numeric_limits<unsigned int>::max() << std::endl;
                return EXIT_SUCCESS;
            }
 */
/*  //FLOTTANTS//
        float un_float; // 32 bits
        double un_float; // 64 bits
*/
/*      //Code pour conaitres les valeurs limites
            #include <iostream>
            #include <iomanip>
            #include <limits>
            int main(){
                {
                float a {0.1};
                float b {0.2};
                auto precision = std::numeric_limits<float>::digits10;
                // nombre de décimales supporté sans perte
                std::cout << "precision : " << precision << std::endl;
                std::cout << std::setprecision(precision+2) << "a + b = " << a + b << std::endl;
                }
                {
                double a {0.1};
                double b {0.2};
                auto precision = std::numeric_limits<double>::digits10;
                std::cout << "precision : " << precision << std::endl;
                std::cout << std::setprecision(precision+2) << "a + b = " << a + b << std::endl;
                }
                return EXIT_SUCCESS;
            }
 */

