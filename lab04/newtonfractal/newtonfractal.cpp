#include "newtonfractal.h"
#include "ui_newtonfractal.h"

NewtonFractal::NewtonFractal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewtonFractal)
{
    ui->setupUi(this);
    this->resize(400, 400);
}

NewtonFractal::~NewtonFractal()
{
    delete ui;
}

void NewtonFractal::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int width = this->width();
    const int height = this->height();
    const int maxIterations = 50;
    const double threshold = 1e-6;

    // Define the complex function f(z) = z^3 - 1
    auto f = [](std::complex<double> z) { return z * z * z - 1.0; };

    // Iterate over each pixel in the widget
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Map pixel coordinates to the complex plane
            double real = (double(x) / width) * 4.0 - 2.0;
            double imag = (double(y) / height) * 4.0 - 2.0;
            std::complex<double> z(real, imag);

            // Apply Newton's method
            int iterations = 0;
            while (iterations < maxIterations) {
                std::complex<double> dz = (f(z + std::complex<double>(1e-6, 0)) - f(z)) / std::complex<double>(1e-6, 0);
                z = z - f(z) / dz;
                if (std::abs(f(z)) < threshold) break;
                iterations++;
            }

            // Set pixel color based on the root converged to
            QColor color = QColor::fromHsvF(double(iterations) / maxIterations, 1.0, 1.0);
            painter.setPen(color);
            painter.drawPoint(x, y);
        }
    }
}
