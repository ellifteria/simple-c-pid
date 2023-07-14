typedef struct {
    double Kp;
    double Ki;
    double Kd;

    double max_output;
    double min_output;

    double max_integral;
    double min_integral;

    double accumulated_error;
    double previous_error;
} PIDController;

double PIDController_get_output(
    PIDController pid,
    double curr_pos,
    double target_pos
) {
    double error = target_pos - curr_pos;

    double integral = pid.accumulated_error + error;

    if (integral > pid.max_integral) {
        integral = pid.max_integral
;
    } else if (integral <  pid.min_integral) {
        integral = pid.min_integral;
    }

    double derivative = error - pid.previous_error;

    double output = (pid.Kp * error) + (pid.Kd * derivative) +
        (pid.Ki * integral);

    if (output > pid.max_output) {
        output = pid.max_output;
    } else if (output <  pid.min_output) {
        output = pid.min_output;
    }

    pid.accumulated_error = integral;
    pid.previous_error = error;

    return output;
}

void main() {
    return 0;
}
