// Initializing rand()
srand(time(NULL));

const int INTERVAL = 5000; // 2 decimales de presición
int circle_points = 0, square_points = 0;
double pi = 0.0;
for(int i = 0; i < INTERVAL*INTERVAL; ++i) {
    //double rand_x = random(-1.0, 1.0);
    //double rand_y = random(-1.0, 1.0);
    double rand_x = double(rand() % (INTERVAL + 1)) / double(INTERVAL);
    double rand_y = double(rand() % (INTERVAL + 1)) / double(INTERVAL);
    // Distance between (x, y) from the origin
    // origin_dist = rand_x**2 + rand_y**2
    double origin_dist = rand_x*rand_x + rand_y*rand_y;
    // Checking if (x, y) lies inside the define
    // circle with R=1
    if (origin_dist <= 1)
        circle_points++;
    // Total number of points generated
    square_points++;    
}
pi = double(4 * circle_points) / double(square_points);

cout << "Final Estimation of Pi = " << fixed << setprecision(2) << pi << endl;