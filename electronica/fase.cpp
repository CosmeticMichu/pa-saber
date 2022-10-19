#include<iostream>

using namespace std;

double f0 = 6.87;

void pre(const string& name);
void aux();
void plot(const string& name, const string& color, const string& title);

int main(int argc, char** argv){

    const string& name = "phivf";
    const string& title = "{/Symbol f} vs f";
    const string& color = "#FF01D1";

    pre(name);
    aux();
    plot(name, color, title);
    return 0;
}

void pre(const string& name){

    const string& title = "Phase diagram";
    const string& font = "helvetica";
    const string& fontsize = "16";
    const string& xlabel = "f[kHz]";
    const string& ylabel = "{/Symbol f}[rad]";

    cout << "set term pdf font '" << font << ", " << fontsize << "'\n";
    cout << "set output '" << name << ".pdf'\n";
    cout << "set tics font '" << font << ", 12'\n";
    cout << "set grid xtics\n";
    cout << "set grid ytics\n";
    cout << "set title '" <<  title << "' font '" << font << ", " << fontsize << "'\n";
    cout << "set title '" <<  title << "'\n";
    cout << "set xlabel '" << xlabel << "'\n";
    cout << "set ylabel '" << ylabel << "'\n";
}

void aux(){
    cout << "set label 'f_0' at " << f0-0.1 << ",-1.1 font 'helvetica-bold'\n";
    cout << "set arrow from " << f0 << ",-1 to " << f0 << ",1.5 nohead dt 2 lw 2\n";
    cout << "set label 'X_C>X_L' at 5.2,0.75 font 'helvetica-bold'\n";
    cout << "set label 'X_C<X_L' at 7.75,-0.5 font 'helvetica-bold'\n";
}

void plot(const string& name, const string& color, const string& title){
    cout << "plot '" << name << ".txt' w lp pt 9 lc '" << color << "' t '" << title << "'\n";
    cout << "set output\n";
    cout << "q";
}
