//Distribuição Normal

#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

void normal_distribution_pdf(const double m, const double s, const int samples) {    
    mt19937 gen(1701); 

    normal_distribution<> distr(m, s);
    
    cout << endl;
    cout << "minimo: " << distr.min() << endl;
    cout << "maximo: " << distr.max() << endl;
    cout << "media: " << fixed << setw(11) << setprecision(10) << distr.mean() << endl;
    cout << "desvio padrao: " << fixed << setw(11) << setprecision(10) << distr.stddev() << endl;

    // Gerando um valor de distribuição
    map<double, int> histogram;
    for (int i = 0; i < samples; ++i) {
        ++histogram[distr(gen)];
    }

    // Mostrando o Resultado
    cout << "Distribuicao para as " << samples << " amostras:" << endl;
    int counter = 0;
    for (const auto& elem : histogram) {
        cout << fixed << setw(11) << ++counter << ": "
            << setw(14) << setprecision(10) << elem.first << endl;
    }
    cout << endl;
}

int main()
{
    double m_dist = 1;
    double s_dist = 1;
    int samples = 10;

    cout << "Use Ctrl-Z para pular a etapa de entrada de dados e usar os valores padroes." << endl;
    cout << "Insira um valor numerico para a media: " << endl;
    cin >> m_dist;
    cout << "Insira um valor numerico para o desvio padrao (> zero): " << endl;
    cin >> s_dist;
    cout << "Insira um valor inteiro para a quantidade de amostras: " << endl;
    cin >> samples;

    normal_distribution_pdf(m_dist, s_dist, samples);
}
