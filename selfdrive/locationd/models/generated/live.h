#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_3(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_19(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_6898201814641298663);
void live_err_fun(double *nom_x, double *delta_x, double *out_2731531531239177106);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_258697847652257420);
void live_H_mod_fun(double *state, double *out_9090898548951532695);
void live_f_fun(double *state, double dt, double *out_9171496604355134652);
void live_F_fun(double *state, double dt, double *out_4618057697060829338);
void live_h_3(double *state, double *unused, double *out_4538801653319691933);
void live_H_3(double *state, double *unused, double *out_575863248760330452);
void live_h_4(double *state, double *unused, double *out_245390277277672403);
void live_H_4(double *state, double *unused, double *out_5206672849366731593);
void live_h_9(double *state, double *unused, double *out_2279431599228473214);
void live_H_9(double *state, double *unused, double *out_3871536391837107228);
void live_h_10(double *state, double *unused, double *out_9059368528696520403);
void live_H_10(double *state, double *unused, double *out_4517710279208805907);
void live_h_12(double *state, double *unused, double *out_2176278969607455995);
void live_H_12(double *state, double *unused, double *out_7313228361105941162);
void live_h_31(double *state, double *unused, double *out_7103464003689301593);
void live_H_31(double *state, double *unused, double *out_4638138585962521341);
void live_h_32(double *state, double *unused, double *out_9018968435170132551);
void live_H_32(double *state, double *unused, double *out_2198238876576723912);
void live_h_13(double *state, double *unused, double *out_4039719206652827388);
void live_H_13(double *state, double *unused, double *out_1517038414910104207);
void live_h_14(double *state, double *unused, double *out_2279431599228473214);
void live_H_14(double *state, double *unused, double *out_3871536391837107228);
void live_h_19(double *state, double *unused, double *out_8916903900802026639);
void live_H_19(double *state, double *unused, double *out_561143459265323953);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}