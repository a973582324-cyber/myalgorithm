import tkinter as tk
import random
import math

def heart_x(t, size=10):
    return size * 16 * (math.sin(t) ** 3)

def heart_y(t, size=10):
    return -size * (13 * math.cos(t) - 5 * math.cos(2 * t) - 2 * math.cos(3 * t) - math.cos(4 * t))

def show_tip(x, y, main_window):
    """在指定位置显示提示窗口（保持显示不消失）"""
    # 更长的提示文本库·
    tips = [
        '家是最小国，国是千万家',
        '爱国情藏于心，报国行见于事',
        '以吾辈之青春，护盛世之中华',
        '从自己做起，从本职岗位做起，为民族复兴贡献智慧和力量',
        '以爱国为底色，用奋斗绘就青春华章',
        '少年强则国强，少年志则国志',
        '以青春之我，筑青春之国',
        '山河万里，皆为家国',
        '躬身实干，不负山河',
        '我以我血荐轩辕’',
        '苟利国家生死以，岂因祸福避趋之',
        '青春献给祖国，热血献给人民',
    ]
    
    # 背景色库（更柔和的色调）
    bg_colors = [
        '#FFE4E1', '#E0F7FA', '#E8F5E9', '#F3E5F5',
        '#FFF8E1', '#E1F5FE', '#F1F8E9', '#FCE4EC'
    ]
    
    # 创建顶级窗口（保留边框，更大尺寸）
    tip_window = tk.Toplevel(main_window)
    tip_window.title('温馨提示')  # 保留标题栏
    tip_window.geometry(f"180x80+{x}+{y}")  # 更大的窗口尺寸
    tip_window.attributes('-topmost', True)  # 窗口置顶，确保可见
    
    # 显示更长的提示文字（调整字体大小）
    tk.Label(
        tip_window,
        text=random.choice(tips),
        bg=random.choice(bg_colors),
        font=('微软雅黑', 12),  # 稍大字体适配长文字
        wraplength=160,  # 自动换行，避免文字溢出
        padx=10,
        pady=10,
        justify=tk.CENTER  # 文字居中
    ).pack(fill=tk.BOTH, expand=True)

def create_heart_animation():
    # 主窗口（隐藏，用于调度）
    root = tk.Tk()
    root.withdraw()  # 不显示主窗口
    
    # 获取屏幕尺寸，让爱心居中
    screen_width = root.winfo_screenwidth()
    screen_height = root.winfo_screenheight()
    center_x = screen_width // 2
    center_y = screen_height // 2
    
    # 生成爱心轮廓点（增加点密度，让爱心更完整）
    heart_points = []
    for i in range(0, 628, 4):  # 步长4，更多点组成更密集的轮廓
        t = i / 100  # 弧度值（0到6.28，覆盖完整爱心曲线）
        x = heart_x(t, size=22)  # 放大爱心尺寸，适配更大窗口
        y = heart_y(t, size=22)
        heart_points.append((x, y))
    
    # 按顺序显示窗口，形成绘制动画
    for index, (x, y) in enumerate(heart_points):
        # 转换为屏幕坐标（居中显示）
        screen_x = int(center_x + x)
        screen_y = int(center_y + y)
        # 每个点延迟80ms显示，形成连贯的绘制效果
        root.after(index * 80, show_tip, screen_x, screen_y, root)
    
    root.mainloop()

if __name__ == "__main__":
    create_heart_animation()