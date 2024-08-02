import matplotlib.pyplot as plt


def draw_flight_path(flight, color, label):
    x_coords = [p[0] for p in flight]
    y_coords = [p[1] for p in flight]
    plt.plot(x_coords, y_coords, marker='o', color=color, label=label)

flight1 = [(1, 1), (2, 2), (3, 3)]                
flight2 = [(1, 1), (1.5, 3), (2, 4), (3, 2)]      
flight3 = [(1, 1), (2, 0.5), (4, 2), (3, 4)]      


plt.figure(figsize=(8, 8))

draw_flight_path(flight1, 'blue', 'Flight 1')
draw_flight_path(flight2, 'green', 'Flight 2')
draw_flight_path(flight3, 'red', 'Flight 3')


plt.title('Flight Paths (Adjusted to Avoid Intersection)')
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.grid(True)
plt.legend()


plt.show()
