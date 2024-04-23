#include "fernleaf.h"
#include "ui_fernleaf.h"

FernLeaf::FernLeaf(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FernLeaf)
{
    ui->setupUi(this);
    this->resize(800, 800);
}

FernLeaf::~FernLeaf()
{
    delete ui;
}


void FernLeaf::paintEvent(QPaintEvent *event)  {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int width = width();
    const int height = height();
    const int numPoints = 100000;
    const double scale = 50.0;

    // Calculate offsets to center the fern leaf
    const double xOffset = width / 2.0 - 100.0;
    const double yOffset = height / 2.0 - 200.0;

    // Define transformation parameters
    double x = 0.0;
    double y = 0.0;

    // Iterate to generate fern leaf
    for (int i = 0; i < numPoints; ++i) {
        double r = qrand() / double(RAND_MAX);

        double xNew, yNew;
        if (r <= 0.01) {
            xNew = 0.0;
            yNew = 0.16 * y;
        } else if (r <= 0.08) {
            xNew = 0.2 * x - 0.26 * y;
            yNew = 0.23 * x + 0.22 * y + 1.6;
        } else if (r <= 0.15) {
            xNew = -0.15 * x + 0.28 * y;
            yNew = 0.26 * x + 0.24 * y + 0.44;
        } else {
            xNew = 0.85 * x + 0.04 * y;
            yNew = -0.04 * x + 0.85 * y + 1.6;
        }

        x = xNew;
        y = yNew;

        // Map point to screen coordinates
        int screenX = int(x * scale + xOffset);
        int screenY = int(y * scale + yOffset);

        // Draw the point
        painter.drawPoint(screenX, screenY);
    }
}


