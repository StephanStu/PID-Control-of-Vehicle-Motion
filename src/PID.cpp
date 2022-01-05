#include "PID.h"
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */
PID::PID() {
    is_initialized = false;
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, double output_lower_bound_, double output_upper_bound_) {
    /**
     * TODO: Initialize PID coefficients (and errors, if needed)
     */
    this->Kp = Kp_;
    this->Ki = Ki_;
    this->Kd = Kd_;
    this->p_error = 0.0;
    this->d_error = 0.0;
    this->i_error = 0.0;
    this->output_lower_bound = output_lower_bound_;
    this->output_upper_bound = output_upper_bound_;
    this->is_initialized = true;
}

void PID::UpdateError(double cte) {
    /**
     * TODO: Update PID errors based on cte.
     */
    if (this->is_initialized){
        this->d_error = cte-(this->p_error);
        this->p_error = cte;
        this->i_error += cte;
    }
    else{
        this->p_error = 0.0;
        this->d_error = 0.0;
        this->i_error = 0.0;
    }
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // TODO: Add your total error calc here!
  double total_error;
  if (this->is_initialized){
    total_error = p_error * Kp + i_error * Ki + d_error * Kd;
  }
  else {
    total_error = 0.0;
  }
  return total_error;
}
