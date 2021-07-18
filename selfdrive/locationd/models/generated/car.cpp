#include "car.h"

namespace {
#define DIM 8
#define EDIM 8
#define MEDIM 8
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 5.991464547107981;

/******************************************************************************
 *                       Code generated with sympy 1.8                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7774286080190926812) {
   out_7774286080190926812[0] = delta_x[0] + nom_x[0];
   out_7774286080190926812[1] = delta_x[1] + nom_x[1];
   out_7774286080190926812[2] = delta_x[2] + nom_x[2];
   out_7774286080190926812[3] = delta_x[3] + nom_x[3];
   out_7774286080190926812[4] = delta_x[4] + nom_x[4];
   out_7774286080190926812[5] = delta_x[5] + nom_x[5];
   out_7774286080190926812[6] = delta_x[6] + nom_x[6];
   out_7774286080190926812[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4840928901255275931) {
   out_4840928901255275931[0] = -nom_x[0] + true_x[0];
   out_4840928901255275931[1] = -nom_x[1] + true_x[1];
   out_4840928901255275931[2] = -nom_x[2] + true_x[2];
   out_4840928901255275931[3] = -nom_x[3] + true_x[3];
   out_4840928901255275931[4] = -nom_x[4] + true_x[4];
   out_4840928901255275931[5] = -nom_x[5] + true_x[5];
   out_4840928901255275931[6] = -nom_x[6] + true_x[6];
   out_4840928901255275931[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_2589938056628881610) {
   out_2589938056628881610[0] = 1.0;
   out_2589938056628881610[1] = 0.0;
   out_2589938056628881610[2] = 0.0;
   out_2589938056628881610[3] = 0.0;
   out_2589938056628881610[4] = 0.0;
   out_2589938056628881610[5] = 0.0;
   out_2589938056628881610[6] = 0.0;
   out_2589938056628881610[7] = 0.0;
   out_2589938056628881610[8] = 0.0;
   out_2589938056628881610[9] = 1.0;
   out_2589938056628881610[10] = 0.0;
   out_2589938056628881610[11] = 0.0;
   out_2589938056628881610[12] = 0.0;
   out_2589938056628881610[13] = 0.0;
   out_2589938056628881610[14] = 0.0;
   out_2589938056628881610[15] = 0.0;
   out_2589938056628881610[16] = 0.0;
   out_2589938056628881610[17] = 0.0;
   out_2589938056628881610[18] = 1.0;
   out_2589938056628881610[19] = 0.0;
   out_2589938056628881610[20] = 0.0;
   out_2589938056628881610[21] = 0.0;
   out_2589938056628881610[22] = 0.0;
   out_2589938056628881610[23] = 0.0;
   out_2589938056628881610[24] = 0.0;
   out_2589938056628881610[25] = 0.0;
   out_2589938056628881610[26] = 0.0;
   out_2589938056628881610[27] = 1.0;
   out_2589938056628881610[28] = 0.0;
   out_2589938056628881610[29] = 0.0;
   out_2589938056628881610[30] = 0.0;
   out_2589938056628881610[31] = 0.0;
   out_2589938056628881610[32] = 0.0;
   out_2589938056628881610[33] = 0.0;
   out_2589938056628881610[34] = 0.0;
   out_2589938056628881610[35] = 0.0;
   out_2589938056628881610[36] = 1.0;
   out_2589938056628881610[37] = 0.0;
   out_2589938056628881610[38] = 0.0;
   out_2589938056628881610[39] = 0.0;
   out_2589938056628881610[40] = 0.0;
   out_2589938056628881610[41] = 0.0;
   out_2589938056628881610[42] = 0.0;
   out_2589938056628881610[43] = 0.0;
   out_2589938056628881610[44] = 0.0;
   out_2589938056628881610[45] = 1.0;
   out_2589938056628881610[46] = 0.0;
   out_2589938056628881610[47] = 0.0;
   out_2589938056628881610[48] = 0.0;
   out_2589938056628881610[49] = 0.0;
   out_2589938056628881610[50] = 0.0;
   out_2589938056628881610[51] = 0.0;
   out_2589938056628881610[52] = 0.0;
   out_2589938056628881610[53] = 0.0;
   out_2589938056628881610[54] = 1.0;
   out_2589938056628881610[55] = 0.0;
   out_2589938056628881610[56] = 0.0;
   out_2589938056628881610[57] = 0.0;
   out_2589938056628881610[58] = 0.0;
   out_2589938056628881610[59] = 0.0;
   out_2589938056628881610[60] = 0.0;
   out_2589938056628881610[61] = 0.0;
   out_2589938056628881610[62] = 0.0;
   out_2589938056628881610[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_4480227765543357581) {
   out_4480227765543357581[0] = state[0];
   out_4480227765543357581[1] = state[1];
   out_4480227765543357581[2] = state[2];
   out_4480227765543357581[3] = state[3];
   out_4480227765543357581[4] = state[4];
   out_4480227765543357581[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4480227765543357581[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4480227765543357581[7] = state[7];
}
void F_fun(double *state, double dt, double *out_2469217242969257698) {
   out_2469217242969257698[0] = 1;
   out_2469217242969257698[1] = 0;
   out_2469217242969257698[2] = 0;
   out_2469217242969257698[3] = 0;
   out_2469217242969257698[4] = 0;
   out_2469217242969257698[5] = 0;
   out_2469217242969257698[6] = 0;
   out_2469217242969257698[7] = 0;
   out_2469217242969257698[8] = 0;
   out_2469217242969257698[9] = 1;
   out_2469217242969257698[10] = 0;
   out_2469217242969257698[11] = 0;
   out_2469217242969257698[12] = 0;
   out_2469217242969257698[13] = 0;
   out_2469217242969257698[14] = 0;
   out_2469217242969257698[15] = 0;
   out_2469217242969257698[16] = 0;
   out_2469217242969257698[17] = 0;
   out_2469217242969257698[18] = 1;
   out_2469217242969257698[19] = 0;
   out_2469217242969257698[20] = 0;
   out_2469217242969257698[21] = 0;
   out_2469217242969257698[22] = 0;
   out_2469217242969257698[23] = 0;
   out_2469217242969257698[24] = 0;
   out_2469217242969257698[25] = 0;
   out_2469217242969257698[26] = 0;
   out_2469217242969257698[27] = 1;
   out_2469217242969257698[28] = 0;
   out_2469217242969257698[29] = 0;
   out_2469217242969257698[30] = 0;
   out_2469217242969257698[31] = 0;
   out_2469217242969257698[32] = 0;
   out_2469217242969257698[33] = 0;
   out_2469217242969257698[34] = 0;
   out_2469217242969257698[35] = 0;
   out_2469217242969257698[36] = 1;
   out_2469217242969257698[37] = 0;
   out_2469217242969257698[38] = 0;
   out_2469217242969257698[39] = 0;
   out_2469217242969257698[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2469217242969257698[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2469217242969257698[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2469217242969257698[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2469217242969257698[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2469217242969257698[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2469217242969257698[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2469217242969257698[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2469217242969257698[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2469217242969257698[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2469217242969257698[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2469217242969257698[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2469217242969257698[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2469217242969257698[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2469217242969257698[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2469217242969257698[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2469217242969257698[56] = 0;
   out_2469217242969257698[57] = 0;
   out_2469217242969257698[58] = 0;
   out_2469217242969257698[59] = 0;
   out_2469217242969257698[60] = 0;
   out_2469217242969257698[61] = 0;
   out_2469217242969257698[62] = 0;
   out_2469217242969257698[63] = 1;
}
void h_25(double *state, double *unused, double *out_7817857624510514042) {
   out_7817857624510514042[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6018009411772908810) {
   out_6018009411772908810[0] = 0;
   out_6018009411772908810[1] = 0;
   out_6018009411772908810[2] = 0;
   out_6018009411772908810[3] = 0;
   out_6018009411772908810[4] = 0;
   out_6018009411772908810[5] = 0;
   out_6018009411772908810[6] = 1;
   out_6018009411772908810[7] = 0;
}
void h_24(double *state, double *unused, double *out_4473412493552802521) {
   out_4473412493552802521[0] = state[4];
   out_4473412493552802521[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8148699389951707709) {
   out_8148699389951707709[0] = 0;
   out_8148699389951707709[1] = 0;
   out_8148699389951707709[2] = 0;
   out_8148699389951707709[3] = 0;
   out_8148699389951707709[4] = 1;
   out_8148699389951707709[5] = 0;
   out_8148699389951707709[6] = 0;
   out_8148699389951707709[7] = 0;
   out_8148699389951707709[8] = 0;
   out_8148699389951707709[9] = 0;
   out_8148699389951707709[10] = 0;
   out_8148699389951707709[11] = 0;
   out_8148699389951707709[12] = 0;
   out_8148699389951707709[13] = 1;
   out_8148699389951707709[14] = 0;
   out_8148699389951707709[15] = 0;
}
void h_30(double *state, double *unused, double *out_7542663562226008153) {
   out_7542663562226008153[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3595889499176274470) {
   out_3595889499176274470[0] = 0;
   out_3595889499176274470[1] = 0;
   out_3595889499176274470[2] = 0;
   out_3595889499176274470[3] = 0;
   out_3595889499176274470[4] = 1;
   out_3595889499176274470[5] = 0;
   out_3595889499176274470[6] = 0;
   out_3595889499176274470[7] = 0;
}
void h_26(double *state, double *unused, double *out_5902407243822697818) {
   out_5902407243822697818[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6724141506997433533) {
   out_6724141506997433533[0] = 0;
   out_6724141506997433533[1] = 0;
   out_6724141506997433533[2] = 0;
   out_6724141506997433533[3] = 0;
   out_6724141506997433533[4] = 0;
   out_6724141506997433533[5] = 0;
   out_6724141506997433533[6] = 0;
   out_6724141506997433533[7] = 1;
}
void h_27(double *state, double *unused, double *out_1715338188777319652) {
   out_1715338188777319652[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4883471487012899782) {
   out_4883471487012899782[0] = 0;
   out_4883471487012899782[1] = 0;
   out_4883471487012899782[2] = 0;
   out_4883471487012899782[3] = 1;
   out_4883471487012899782[4] = 0;
   out_4883471487012899782[5] = 0;
   out_4883471487012899782[6] = 0;
   out_4883471487012899782[7] = 0;
}
void h_29(double *state, double *unused, double *out_8486173415127670588) {
   out_8486173415127670588[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7419688268305106423) {
   out_7419688268305106423[0] = 0;
   out_7419688268305106423[1] = 1;
   out_7419688268305106423[2] = 0;
   out_7419688268305106423[3] = 0;
   out_7419688268305106423[4] = 0;
   out_7419688268305106423[5] = 0;
   out_7419688268305106423[6] = 0;
   out_7419688268305106423[7] = 0;
}
void h_28(double *state, double *unused, double *out_7412061908754207767) {
   out_7412061908754207767[0] = state[5];
   out_7412061908754207767[1] = state[6];
}
void H_28(double *state, double *unused, double *out_1130866911715212843) {
   out_1130866911715212843[0] = 0;
   out_1130866911715212843[1] = 0;
   out_1130866911715212843[2] = 0;
   out_1130866911715212843[3] = 0;
   out_1130866911715212843[4] = 0;
   out_1130866911715212843[5] = 1;
   out_1130866911715212843[6] = 0;
   out_1130866911715212843[7] = 0;
   out_1130866911715212843[8] = 0;
   out_1130866911715212843[9] = 0;
   out_1130866911715212843[10] = 0;
   out_1130866911715212843[11] = 0;
   out_1130866911715212843[12] = 0;
   out_1130866911715212843[13] = 0;
   out_1130866911715212843[14] = 1;
   out_1130866911715212843[15] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7774286080190926812) {
  err_fun(nom_x, delta_x, out_7774286080190926812);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4840928901255275931) {
  inv_err_fun(nom_x, true_x, out_4840928901255275931);
}
void car_H_mod_fun(double *state, double *out_2589938056628881610) {
  H_mod_fun(state, out_2589938056628881610);
}
void car_f_fun(double *state, double dt, double *out_4480227765543357581) {
  f_fun(state,  dt, out_4480227765543357581);
}
void car_F_fun(double *state, double dt, double *out_2469217242969257698) {
  F_fun(state,  dt, out_2469217242969257698);
}
void car_h_25(double *state, double *unused, double *out_7817857624510514042) {
  h_25(state, unused, out_7817857624510514042);
}
void car_H_25(double *state, double *unused, double *out_6018009411772908810) {
  H_25(state, unused, out_6018009411772908810);
}
void car_h_24(double *state, double *unused, double *out_4473412493552802521) {
  h_24(state, unused, out_4473412493552802521);
}
void car_H_24(double *state, double *unused, double *out_8148699389951707709) {
  H_24(state, unused, out_8148699389951707709);
}
void car_h_30(double *state, double *unused, double *out_7542663562226008153) {
  h_30(state, unused, out_7542663562226008153);
}
void car_H_30(double *state, double *unused, double *out_3595889499176274470) {
  H_30(state, unused, out_3595889499176274470);
}
void car_h_26(double *state, double *unused, double *out_5902407243822697818) {
  h_26(state, unused, out_5902407243822697818);
}
void car_H_26(double *state, double *unused, double *out_6724141506997433533) {
  H_26(state, unused, out_6724141506997433533);
}
void car_h_27(double *state, double *unused, double *out_1715338188777319652) {
  h_27(state, unused, out_1715338188777319652);
}
void car_H_27(double *state, double *unused, double *out_4883471487012899782) {
  H_27(state, unused, out_4883471487012899782);
}
void car_h_29(double *state, double *unused, double *out_8486173415127670588) {
  h_29(state, unused, out_8486173415127670588);
}
void car_H_29(double *state, double *unused, double *out_7419688268305106423) {
  H_29(state, unused, out_7419688268305106423);
}
void car_h_28(double *state, double *unused, double *out_7412061908754207767) {
  h_28(state, unused, out_7412061908754207767);
}
void car_H_28(double *state, double *unused, double *out_1130866911715212843) {
  H_28(state, unused, out_1130866911715212843);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
