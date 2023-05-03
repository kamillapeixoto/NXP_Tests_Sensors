%% Power Supply Characterization
% This script finds the equation that describes the current and voltage
% readings from the power supply using the blue amplifier board.

% Kamilla Peixoto 02/05/2023

%% Import Data from Excel file

% Open Circuit experiment
data0 = table2array(readtable('Characterization_Data.xlsx', 'Sheet',1, 'Range','A4:D27'));

% 5 ohms Experiment
data5 = table2array(readtable('Characterization_Data.xlsx', 'Sheet',2, 'Range','A4:D21'));

%% Fit data
fit_voltage = fit(data0(:, 2), data0(:, 1),'poly1');
fit_current = fit(data5(:, 4), data5(:, 3),'poly1');

%% Plot Comparison
% Convert from cfit to matrix
fit_voltage_coeff = coeffvalues(fit_voltage);
fit_current_coeff = coeffvalues(fit_current);

figure(1);
plot(data0(:, 2),polyval(fit_voltage_coeff,data0(:, 2)), 'LineWidth',3, 'Color','green');
hold on
plot(data0(:, 2), data0(:, 1), 'Color','blue','Marker','.', 'LineStyle','none', 'MarkerSize',10);
legend('$0.0088x -0.2734$','Experimental Data', 'Location','southeast','interpreter','latex');
xlim([0, data0(end, 2)+50]);
ylim([0, 32]);
title('Open Circuit Experiment','interpreter','latex')
xlabel('Counts','interpreter','latex')
ylabel('Voltage (V)','interpreter','latex')

figure(2);
plot(data5(:, 4),polyval(fit_current_coeff,data5(:, 4)), 'LineWidth',3, 'Color','green');
hold on
plot(data5(:, 4), data5(:, 3), 'Color','blue','Marker','.', 'LineStyle','none', 'MarkerSize',10);
legend('$0.0017x - 0.0139$','Experimental Data', 'Location','southeast','interpreter','latex');
xlim([0, data5(end, 4)+50]);
ylim([0, data5(end,3)+0.5]);
title('5 Ohms Experiment','interpreter','latex')
xlabel('Counts','interpreter','latex')
ylabel('Voltage (V)','interpreter','latex')

%% Data Validation
% Use one experiment to validate the other - write it properly later

figure(3);
plot(data5(:, 2),polyval(fit_voltage_coeff,data5(:, 2)), 'LineWidth',3, 'Color','green');
hold on
plot(data5(:, 2), data5(:, 1), 'Color','blue','Marker','.', 'LineStyle','none', 'MarkerSize',10);
legend('$0.0088x -0.2734$','Experimental Data', 'Location','southeast','interpreter','latex');
xlim([0, data5(end, 2)+50]);
ylim([0, data5(end,1)+0.2]);
title('5 Ohms Experiment','interpreter','latex')
xlabel('Counts','interpreter','latex')
ylabel('Voltage (V)','interpreter','latex')

%% Analyze data

% Voltage
data19 = table2array(readtable('Data_19V_OpenCircuit'));
data19 = data19(1:500,5);

voltage_avg = mean(data19);
cost_func = 'MSE';
MSE_voltage = goodnessOfFit(data19,19*ones(size(data19)),cost_func);


%Current
data4A = table2array(readtable('Data_4A_1610mV'));
data4A = data4A(1:700,4);

current_avg = mean(data4A);
MSE_current = goodnessOfFit(data4A,4*ones(size(data4A)),cost_func);

