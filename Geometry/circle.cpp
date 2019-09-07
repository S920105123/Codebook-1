/* Common tangent, circle is a point c and radius r */
void get_tangent(Point c, double r1, double r2, vector<Line> &ans) {
    double r = r2 - r1;
    double z = c.x*c.x + c.y*c.y;
    double d = z - r*r;
    if (d < -EPS) return;
    d = sqrt(abs(d));
    Line l;
    l.a = (c.x * r + c.y * d) / z;
    l.b = (c.y * r - c.x * d) / z;
    l.c = r1;
    ans.push_back(l);
}
vector<Line> tangents(Circle a, Circle b) {
	// Tangent line of two circles, may have 0, 1, 2, 3, 4, inf solutions
	// In case 0 or inf (a = b), no line will be reported. Otherwise,
	// this program always find 4 lines, even if some of them are the same.
    vector<Line> ans;
    for (int i=-1; i<=1; i+=2)
        for (int j=-1; j<=1; j+=2)
            get_tangent(b.c-a.c, a.r*i, b.r*j, ans);
    for (size_t i=0; i<ans.size(); ++i)
        ans[i].c -= ans[i].a * a.c.x + ans[i].b * a.c.y;
    return ans;
}
// Circle-line intersection
double r, a, b, c; // input, circle:((0,0),r), line:ax+by+c=0
double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
if (c*c > r*r*(a*a+b*b)+EPS)
    puts ("no points");
else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
    puts ("1 point");
    cout << x0 << ' ' << y0 << '\n';
}
else {
    double d = r*r - c*c/(a*a+b*b);
    double mult = sqrt (d / (a*a+b*b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    puts ("2 points");
    cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
}
// Circle-circle intersection
// Circle ((0,0),r1) and ((x2,y2),r2)
// Then reduce to circle 1 intersect with line Ax+By+C
// A=-2*x_2, B=-2*y_2, C=(x_2)^2+(y_2)^2+(r_1)^2-(r_2)^2
// Special case: two circle are the same => inf points
