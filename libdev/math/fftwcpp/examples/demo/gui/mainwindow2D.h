#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QVector>

class QwtPlot;
class QLinePlot;

#include "functions/functionfactory.h"
#include "functions/complexfunctionfactory.h"
#include "calculationmanager.h"

#include "fftwcpp.h"

namespace Ui {
class MainWindow;
}

class QBoxLayout;
class QVBoxLayout;
class QButtonGroup;
class PlotComplexData;

enum ComplexType{Amplitude, Phase };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startFFT();
    void on_pushButtonStartFFT_clicked();
    void on_actionQuit_triggered();

    void on_comboBoxFunctionsAmplitude_currentIndexChanged(int index);
    void on_comboBoxFunctionsPhase_currentIndexChanged(int index);
    void on_checkBoxPhaseShift_stateChanged(int state);
    void on_checkBoxPhaseUnwrap_stateChanged(int state);
    void onButtonGroupFFTDimensionButtonClicked(int id);

    void onFunctionParameterChanged(double value);
    void getResultsAndPlot();

    void on_checkBoxCorrectShiftDisplay_stateChanged(int arg1);
    void on_comboBoxDataPoints_currentIndexChanged(int index);
    void updateFunctionParameterSettings();
    void updateProgressBar(int percent);
    void onDimensionsChanged(size_t N);

private:
//    void setupPlot(QLinePlot *plot, QString title);
    void setupWidgets();
    void addFunctionParameter(ComplexType type, QBoxLayout * layout, QString valueName, double value, double min, double max);
    void createFunctionParameterList(ComplexType type, int index);
    void applyFunctionParameterSetting(QSharedPointer<FunctionFactory> function, QMap<QString, QWidget*> map);


private:
    Ui::MainWindow *ui;
    QList<QSharedPointer<FunctionFactory>> functionListAmplitude;
    QList<QSharedPointer<FunctionFactory>> functionListPhase;
    QSharedPointer<ComplexFunctionFactory> complexFF;
    QScopedPointer<CalculationManager> calculationManager;
    QThread * thread; // Qt Object, no smart pointer needed
    QMap<QString, QWidget*> mapPhaseParameterWidgets;
    QMap<QString, QWidget*> mapAmplitudeParameterWidgets;
    QButtonGroup * buttonGroupFFTDimension;

    QVector<PlotComplexData*> plotWidgetList;
    FFT<double> fft;
public:


};

#endif // MAINWINDOW_H
