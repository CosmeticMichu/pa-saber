#include <iostream>
#include <cmath>

using namespace std;

double f0 = 6.87;

void pre(double f1, double f2, const string& name);
void aux(double f1, double f2, double v);
void linreg(const string& name);
void plot(const string& name, const string& color, const string& title);

int main(int argc, char** argv){

//CONSTANTES
    double f1 = 6.07;
    double f2 = 7.87;
    double v = sqrt(2);

    const string& name = "Avvf";
    const string& color = "#3CF800";
    const string& title = "A_v vs f";

    pre(f1, f2, name);
    aux(f1, f2, v);
    linreg(name);
    plot(name, color, title);

    return 0;
}


void pre(double f1, double f2, const string& name){

    const string& title = "Bode diagram semilogarithmic scale";
    const string& font = "helvetica";
    const string& fontsize = "16";
    const string& xlabel = "f[khz]";
    const string& ylabel = "A_V=(V_{out}/V_{in})[dB]";

    cout << "set term pdf font '" << font << ", " << fontsize << "'\n";
    cout << "set output '" << name << ".pdf'\n";
    cout << "set tics font '" << font << ", 12'\n";
    cout << "set logscale x\n";
    cout << "set xtics (4,5,6,7,8,9,10)\n";
    cout << "set xrange [4.5:10] noextend\n";
    cout << "set yrange [-23:-13]\n";
    cout << "set grid xtics\n";
    cout << "set grid ytics\n";
    cout << "set title '" <<  title << "' font '" << font << ", " << fontsize << "'\n";
    cout << "set title '" <<  title << "'\n";
    cout << "set xlabel '" << xlabel << "'\n";
    cout << "set ylabel '" << ylabel << "'\n";
    cout << "set label 'f_0' at " << f0-0.15 << ",-23.5 font 'helvetica-bold'\n";
    cout << "set label 'f_1= " << f1 << " kHz' at " << f1+0.05 << ",-22.3\n";
    cout << "set label 'f_2= " << f2 << " kHz' at " << f2+0.05 << ",-22.3\n";
}

void aux(double f1, double f2, double v){

    cout << "set arrow from " << f1 << ",-23 to " << f1 << ",-13 nohead dt 2 lw 2\n";
    cout << "set arrow from " << f2 << ",-23 to " << f2 << ",-13 nohead dt 2 lw 2\n";
    cout << "set arrow from " << f0 << ",-23 to " << f0 << ",-13 nohead dt 2 lw 2\n";
}

void linreg(const string& name){
    cout << "f1(x)=a1*x+b1\n";
    cout << "f2(x)=a2*x+b2\n";
    cout << "set print '" << name << "linf>.log'\n";
    cout << "print '//LINEAR FIT (f>f0)//'\n";
    cout << "unset print \n";
    cout << "set fit logfile '" << name << "linf>.log'\n";
    cout << "set fit quiet\n";
    cout << "fit f1(x) '" << name << ".txt' every ::1::20 via a1, b1\n";
    cout << "set print '" << name << "linf<.log'\n";
    cout << "print '//LINEAR FIT (f<f0)//'\n";
    cout << "unset print \n";
    cout << "set fit logfile '" << name << "linf<.log'\n";
    cout << "set fit quiet\n";
    cout << "fit f2(x) '" << name << ".txt' every ::20::41 via a2, b2\n";
}

void plot(const string& name, const string& color, const string& title){
    cout << "plot '" << name << ".txt' w lp lt 5 lc '" << color << "' t '" << title << "', f1(x) dt 4 lw 2 lc -1 t 'Fit for f>f_0', f2(x) dt 5 lw 2 lc -1 t 'Fit for f<f_0'\n";
    cout << "set output\n";
    cout << "q";
}
