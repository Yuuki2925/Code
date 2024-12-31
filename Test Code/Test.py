import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Tạo dữ liệu giả
data = {
    'Rainfall': [120, 150, 200, 250, 300, 350, 400, 450, 500, 550],  # Lượng mưa (mm)
    'Temperature': [30, 32, 34, 33, 35, 37, 36, 39, 40, 41],  # Nhiệt độ (C)
    'Humidity': [80, 75, 70, 65, 60, 55, 50, 45, 40, 35],  # Độ ẩm (%)
    'WaterLevel': [5.2, 5.5, 5.8, 6.0, 6.3, 6.5, 6.7, 7.0, 7.2, 7.5]  # Mức nước (m)
}

# Chuyển đổi thành DataFrame
df = pd.DataFrame(data)

# Bước 2: Tách dữ liệu thành đầu vào (X) và đầu ra (y)
X = df[['Rainfall', 'Temperature', 'Humidity']]  # Các yếu tố đầu vào
y = df['WaterLevel']  # Mức nước là đầu ra

# Bước 3: Chia dữ liệu thành tập huấn luyện và tập kiểm tra
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Bước 4: Xây dựng mô hình hồi quy tuyến tính
model = LinearRegression()
model.fit(X_train, y_train)

# Bước 5: Dự đoán mức nước trên tập kiểm tra
y_pred = model.predict(X_test)

# Bước 6: Đánh giá mô hình bằng MSE
mse = mean_squared_error(y_test, y_pred)
print(f'Mean Squared Error: {mse}')

# Chuyển y_test và y_pred sang dạng numpy arrays
y_test = y_test.reset_index(drop=True)  # Đảm bảo chỉ số đồng nhất
y_pred = np.array(y_pred)

# Bước 7: Vẽ đồ thị động thay đổi theo dự đoán

# Tạo một đồ thị trống
fig, ax = plt.subplots()
ax.set_xlim(0, len(y_test))  # Trục x đại diện cho thời gian (khung hình)
ax.set_ylim(min(min(y_test), min(y_pred)) - 0.5, max(max(y_test), max(y_pred)) + 0.5)
ax.set_xlabel('Khung hình (Thời gian)')
ax.set_ylabel('Mực nước (m)')
ax.set_title('Dự báo lũ lụt - Thay đổi mực nước theo thời gian')

# Vẽ các đường ban đầu
line_actual, = ax.plot([], [], 'b-', label='Mực nước thực tế', linewidth=2)  # Đường mực nước thực tế
line_predicted, = ax.plot([], [], 'r-', label='Mực nước dự đoán', linewidth=2)  # Đường mực nước dự đoán

# Hàm cập nhật đồ thị trong thời gian thực
def update_plot(frame):
    # Lấy dữ liệu hiện tại
    x_values = range(frame)  # Trục x là các khung hình
    current_y_test = y_test[:frame]  # Mực nước thực tế
    current_y_pred = y_pred[:frame]  # Mực nước dự đoán

    # Cập nhật đường mực nước thực tế
    line_actual.set_data(x_values, current_y_test)

    # Cập nhật đường mực nước dự đoán
    line_predicted.set_data(x_values, current_y_pred)

    return line_actual, line_predicted

# Tạo animation
ani = animation.FuncAnimation(fig, update_plot, frames=len(y_test) + 1, interval=1000, blit=True)

plt.legend()
plt.show()
