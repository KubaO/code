#ifndef PLOTCOMPLEXDATA_H
#define PLOTCOMPLEXDATA_H

#include <QWidget>
#include <QScopedPointer>
#include <QSize>

#include <vector>
using std::vector;

#include <complex>
using std::complex;

#include "fftallocator.h"
using namespace fftwcpp;

namespace Ui {
class PlotComplexData;
}

class PlotComplexDataPrivate;
class QGridLayout;
class QwtPlot;

class PlotComplexData : public QWidget
{
    Q_OBJECT

public:
    explicit PlotComplexData(QWidget *parent = 0);
    virtual ~PlotComplexData();

    enum class Dimension {
        undefined = 0,
        oneDim = 1, // 1D
        twoDim = 2  // 2D
    };

    void setTitle(QString title);
    void setRemovePhaseFlipping(bool doRemove);
    void updatePlotData(const std::vector<complex<double>,fftalloc<complex<double> > > & data, QSize size);
    void updatePlotData(vector<double> & dataAmplitude, vector<double> & dataPhase, QSize size);

private:
    void createPlotWidgets(PlotComplexData::Dimension dimension);
    vector<double> createAxis(size_t length);
    void setupLinePlot(QwtPlot * plot);
    void setupMatrixPlot(QwtPlot * plot, const QString title);


protected:
    const QScopedPointer<PlotComplexDataPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(PlotComplexData)

private:
    Ui::PlotComplexData *ui;
    QGridLayout *gridLayoutPlots;
};

#endif // PLOTCOMPLEXDATA_H
