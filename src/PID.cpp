#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {
delete d_buffer ; // releasing memory
  }

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  // Initialize buffer variables as well
  prev_error = -0.7598;
  d_buffer = new double[1]; // reserve memory on heap
  d_sum = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_error;

  d_sum -= d_buffer[0];
  d_buffer[0] = d_error;
  d_sum += d_buffer[0];
  d_error = d_sum;
  prev_error = cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return (Kp*p_error + Ki*i_error + Kd*d_error); // TODO: Add your total error calc here!
}