%% Extract Data
[file_name, file_path] = uigetfile('*.txt');
experimental_data = load (fullfile(file_path, file_name));
time_stamp = experimental_data(:,1);
desired_pos = experimental_data(:,2);
actual_pos = experimental_data(:,3);
torque_int = experimental_data(:,4);

t_sim = cumsum(time_stamp);

ax1 = subplot(2,1,1);
plot(t_sim, desired_pos, t_sim, actual_pos);
xlabel('Time [s]'); ylabel('Actuator Position [º]');
legend('Reference', 'Actual');

ax2 = subplot(2,1,2);
plot(t_sim, torque_int);
xlabel('Time [s]'); ylabel('Interaction Torque [ADC Counts]');


linkaxes([ax1, ax2], 'x');
