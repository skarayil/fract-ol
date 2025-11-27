# 🌀 Fract-ol - Fraktal Görselleştirme Programı

<div align="center">

![42 School](https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Graphics](https://img.shields.io/badge/Project-fract--ol-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

**MiniLibX grafik kütüphanesi kullanarak matematiksel fraktalların görselleştirilmesi**

*Bu proje, karmaşık sayılar, matematiksel iterasyonlar ve grafik programlama ile fraktal geometrisinin büyüleyici dünyasını keşfetme fırsatı sunar.*

[Kurulum](#-kurulum) • [Kullanım](#-kullanım) • [Özellikler](#-desteklenen-özellikler) • [Bonus](#-bonus-kısmı)

</div>

---

## 🎯 Projenin Amacı

<img align="right" alt="Fractal Animation" width="300" src="https://media.giphy.com/media/l0HlQXlQ3nHyLMvte/giphy.gif">

Bu proje, **matematiksel fraktalların gerçek zamanlı görselleştirilmesi** amacıyla grafik programlama ve karmaşık sayı matematiğini bir araya getirir:

### 🎓 **Ana Öğrenme Hedefleri:**

#### 🖼️ **Grafik Programlama**
- MiniLibX kütüphanesi ile 2D grafik rendering
- Pixel manipulation ve image buffer yönetimi
- Real-time rendering ve frame management
- Color mapping ve visual effects

#### 🔢 **Karmaşık Sayı Matematiği**
- Complex number operations (toplama, çarpma)
- Mandelbrot ve Julia set algoritmaları
- Mathematical iteration ve convergence testing
- Coordinate system transformations

#### 🎨 **Fraktal Geometrisi**
- Fractal theory ve self-similarity patterns
- Escape-time algorithms implementation
- Smooth coloring ve gradient mapping
- Zoom ve pan transformations

#### 🎮 **Event Handling**
- Keyboard input processing
- Mouse event handling (zoom, pan)
- Window management ve user interaction
- Real-time parameter adjustment

#### 🧮 **Optimizasyon Teknikleri**
- Efficient iteration algorithms
- Memory-optimized rendering
- Performance tuning ve bottleneck elimination
- Adaptive iteration depth

#### 🏗️ **Modüler Tasarım**
- Clean code architecture
- Function modularity ve separation of concerns
- Cross-platform compatibility (Linux/macOS)
- Maintainable codebase structure

---

## ✨ Desteklenen Özellikler

<div align="center">

![Fractals](https://img.shields.io/badge/Fractals-Multiple-brightgreen?style=for-the-badge)
![Interactive](https://img.shields.io/badge/Interactive-Zoom%20%26%20Pan-blue?style=for-the-badge)
![Colorful](https://img.shields.io/badge/Colorful-Schemes-orange?style=for-the-badge)

</div>

### 📋 **Desteklenen Fraktallar**

| Fraktal | Açıklama | Parametreler | Özellik |
|---------|----------|--------------|---------|
| **Mandelbrot** | Z = Z² + C iterasyonu | Yok (sabit) | Self-similarity, infinite zoom |
| **Julia** | Z = Z² + C (sabit C) | c_real, c_imag | Parameter-dependent patterns |

### 🎨 **Görsel Özellikler**

#### 🖼️ **Render Özellikleri**

```
Window Size: 800x600 pixels
Iteration Depth: 100-500 (adaptive)
Color Schemes: 10 different palettes
Smooth Coloring: ✅ Continuous gradient
```

#### 🎯 **İnteraktif Kontroller**

| Kontrol | Fonksiyon | Açıklama |
|---------|-----------|----------|
| **Mouse Wheel** | Zoom In/Out | Fare konumunda yakınlaştırma |
| **Arrow Keys** | Pan View | Görüntü alanını kaydırma |
| **C Key** | Change Colors | Renk şemasını değiştirme |
| **ESC** | Exit | Programdan çıkış |

---

## 🎁 Bonus Kısmı

<div align="center">

![Extra Fractals](https://img.shields.io/badge/Extra-Fractals-gold?style=for-the-badge)
![Advanced Features](https://img.shields.io/badge/Advanced-Features-purple?style=for-the-badge)

</div>

Bonus kısmı, ek fraktal türleri ve gelişmiş görselleştirme özellikleri içerir:

### 🔮 **Ek Fraktallar**

| Fraktal | Formül | Özellik |
|---------|--------|---------|
| **Tricorn** | Z = conj(Z)² + C | Mandelbrot'un konjuge versiyonu |
| **Celtic** | Z = \|real(Z²)\| + imag(Z²) + C | Absolute value variation |

### 🎨 **Gelişmiş Görselleştirme**

#### 🌈 **Renk Paletleri**
- 10 farklı renk şeması
- Smooth gradient transitions
- Psychedelic color patterns
- Custom color interpolation

#### ⚡ **Performance Enhancements**
- Adaptive iteration depth based on zoom level
- Optimized mathematical calculations
- Efficient memory management
- Fast rendering algorithms

#### 🎯 **User Experience**
- Intuitive controls
- Visual feedback
- Smooth animations
- Informative usage instructions

---

## 📁 Dosya Yapısı

### 🐧 **Linux Version**

```
fract-ol/linux/
│
├── 📄 Makefile                     # Build automation
├── 📋 include/fractol.h            # Main header file
│
├── 📂 sources/
│   ├── 🚀 main.c                   # Program entry point
│   ├── 🎨 color.c                  # Color scheme management
│   ├── 🌀 fractals.c               # Fractal algorithms
│   ├── 🎮 hooks.c                  # Event handlers
│   ├── 📝 parser.c                 # Input parsing
│   ├── 🖼️ render.c                 # Rendering engine
│   ├── 🔍 zoom.c                   # Zoom functionality
│   └── 🔢 atod.c                   # String to double conversion
│
├── 📂 bonus/
│   ├── 📋 include/fractol_bonus.h
│   └── 📂 sources/
│       ├── main_bonus.c
│       ├── color_bonus.c
│       ├── fractals_bonus.c
│       ├── hooks_bonus.c
│       ├── parser_bonus.c
│       ├── render_bonus.c
│       └── zoom_bonus.c
│
└── 📂 minilibx-linux/              # MiniLibX graphics library
```

### 🍎 **macOS Version**

```
fract-ol/macos/
│
├── 📄 Makefile                     # macOS-specific build
├── 📋 include/fractol.h
│
├── 📂 sources/                     # Same structure as Linux
└── 📂 minilibx-opengl/            # MiniLibX OpenGL version
```

### 📊 **Dosya Açıklamaları**

| Dosya | İçerik | Sorumluluk |
|-------|--------|------------|
| `main.c` | Program initialization | Window creation, main loop |
| `fractals.c` | Fractal calculations | Mandelbrot, Julia algorithms |
| `render.c` | Image generation | Pixel rendering, display |
| `color.c` | Color computation | Palette management, mapping |
| `hooks.c` | Event handling | Keyboard/mouse events |
| `zoom.c` | View transformation | Zoom, pan calculations |
| `parser.c` | Argument parsing | Input validation, error handling |

---

## 🚀 Kurulum

### 📋 **Ön Gereksinimler**

![GCC](https://img.shields.io/badge/GCC-Required-red?style=flat-square&logo=gnu&logoColor=white)
![Make](https://img.shields.io/badge/Make-Required-blue?style=flat-square&logo=gnu&logoColor=white)
![X11](https://img.shields.io/badge/X11-Linux%20Only-green?style=flat-square&logo=linux&logoColor=white)

#### 🐧 **Linux Gereksinimleri**

```bash
# X11 development libraries
sudo apt-get install libx11-dev libxext-dev

# Build essentials
sudo apt-get install build-essential
```

#### 🍎 **macOS Gereksinimleri**

```bash
# Xcode Command Line Tools
xcode-select --install

# No additional dependencies needed
```

### 📥 **Repository Klonlama**

```bash
# Projeyi yerel sisteminize klonlayın
git clone https://github.com/skarayil/fract-ol.git
cd fract-ol
```

### 🔨 **Derleme İşlemi**

#### 🐧 **Linux**

```bash
# Linux dizinine git
cd linux

# Temel versiyonu derle
make

# Bonus versiyonu derle
make bonus

# Temizlik işlemleri
make clean          # Object dosyalarını sil
make fclean         # Tüm oluşturulan dosyaları sil
make re             # Yeniden derle
```

#### 🍎 **macOS**

```bash
# macOS dizinine git
cd macos

# Aynı komutlar geçerli
make
make bonus
```

### 📦 **Çıktı Dosyaları**

```bash
fractol             # Main executable
fractol_bonus       # Bonus executable
```

---

## 💻 Kullanım

### 🖥️ **Temel Kullanım**

#### 🟢 **Mandelbrot Fraktalı**

```bash
# Mandelbrot setini görüntüle
./fractol mandelbrot

# Çıktı:
# 800x600 pencerede Mandelbrot fraktalı görüntülenir
```

#### 🟡 **Julia Fraktalı**

```bash
# Julia setini belirli parametrelerle görüntüle
./fractol julia 0.3 0.5
./fractol julia -0.4 0.6
./fractol julia -0.75 0.11
./fractol julia -0.8 0.156

# Parametreler: c_real c_imaginary
# Değer aralığı: -4.0 ile 4.0 arası
```

### 🎁 **Bonus Kullanım**

#### 🟣 **Ek Fraktallar**

```bash
# Celtic fraktalı
./fractol_bonus celtic

# Tricorn fraktalı
./fractol_bonus tricorn
```

### 🎮 **İnteraktif Kontroller**

#### ⌨️ **Klavye Kontrolleri**

| Tuş | Fonksiyon | Açıklama |
|-----|-----------|----------|
| **ESC** | Exit | Programdan çık |
| **↑** | Pan Up | Yukarı kaydır |
| **↓** | Pan Down | Aşağı kaydır |
| **←** | Pan Left | Sola kaydır |
| **→** | Pan Right | Sağa kaydır |
| **C** | Color Cycle | Renk şemasını değiştir |

#### 🖱️ **Fare Kontrolleri**

| Aksiyon | Fonksiyon | Açıklama |
|---------|-----------|----------|
| **Scroll Up** | Zoom In | Fare konumunda yakınlaştır |
| **Scroll Down** | Zoom Out | Fare konumunda uzaklaştır |

### 📝 **Kullanım Örnekleri**

#### 🔍 **Mandelbrot Keşfi**

```bash
# Program başlat
./fractol mandelbrot

# İnteraktif kullanım:
# 1. Mouse wheel ile ilginç bölgelere zoom yap
# 2. Arrow keys ile hareket et
# 3. C tuşu ile renkleri değiştir
# 4. Derin zoom seviyelerinde detayları keşfet
```

#### 🌀 **Julia Set Keşfi**

```bash
# Klasik Julia parametreleri
./fractol julia -0.4 0.6          # Dendrite pattern
./fractol julia 0.285 0.01         # Spiral pattern
./fractol julia -0.8 0.156         # Dragon pattern
./fractol julia -0.75 0.11         # Douady rabbit

# Her parametrede farklı pattern'lar keşfet
```

#### 🎨 **Görsel Özelleştirme**

```bash
# Program çalışırken:
# 1. C tuşuna basarak 10 farklı renk paleti dene
# 2. Zoom yaparak iteration depth'in otomatik arttığını gör
# 3. Farklı zoom seviyelerinde renk değişimlerini incele
```

---

## 🧪 Test Senaryoları

### ✅ **Temel Fonksiyonalite Testleri**

#### 📊 **Render Testleri**

```bash
# Mandelbrot rendering
./fractol mandelbrot
# Beklenen: 800x600 pencerede tam Mandelbrot seti

# Julia rendering farklı parametrelerle
./fractol julia 0.3 0.5
./fractol julia -0.4 0.6
# Beklenen: Her parametrede farklı Julia pattern'ı
```

#### 🎨 **Görsel Kalite Testleri**

```bash
# Smooth coloring kontrolü
# - Renk geçişlerinin smooth olması
# - Banding olmaması
# - Gradient quality yüksek olmalı

# Zoom kalitesi
# - Derin zoom'da detay kaybı olmamalı
# - Iteration depth adaptive artmalı
# - Pixelation minimize edilmeli
```

### 🎮 **İnteraktivite Testleri**

#### ⌨️ **Keyboard Input Testleri**

```bash
# ESC tuşu testi
# Beklenen: Program gracefully kapanmalı

# Arrow key testi
# Beklenen: Smooth pan movements

# C tuşu testi
# Beklenen: Renk palette cycle smooth olmalı
```

#### 🖱️ **Mouse Event Testleri**

```bash
# Zoom in testi (scroll up)
# - Fare konumunda merkez kalmalı
# - Zoom progressive olmalı
# - Iteration depth artmalı

# Zoom out testi (scroll down)
# - Smooth zoom out
# - Iteration depth azalmalı (100'den az olmamalı)
# - View boundaries korunmalı
```

### 🎁 **Bonus Testleri**

#### 🔮 **Ek Fraktal Testleri**

```bash
# Celtic fractal test
./fractol_bonus celtic
# Beklenen: Celtic pattern'ı doğru render edilmeli

# Tricorn fractal test
./fractol_bonus tricorn
# Beklenen: Tricorn (Mandelbar) seti görünmeli
```

### ⚠️ **Hata Durumu Testleri**

#### 🚫 **Invalid Input Testleri**

```bash
# Eksik parametre
./fractol
# Beklenen: Usage mesajı

# Geçersiz fraktal ismi
./fractol unknown
# Beklenen: Error + Usage mesajı

# Julia için eksik parametre
./fractol julia 0.3
# Beklenen: Error mesajı

# Julia için geçersiz parametre
./fractol julia abc def
# Beklenen: "Invalid number format" error

# Julia için out-of-range parametre
./fractol julia 5.0 5.0
# Beklenen: "Parameters must be between -4.0, 4.0" error
```

#### 🛡️ **Memory ve Resource Testleri**

```bash
# Memory leak kontrolü
valgrind --leak-check=full ./fractol mandelbrot
# Test: 30 saniye etkileşim, ardından ESC ile çıkış
# Beklenen: No memory leaks

# Multiple window close test
# Test: Window'u X button ile kapat
# Beklenen: Proper cleanup, no segfault

# Rapid interaction test
# Test: Hızlı zoom in/out, pan, color change
# Beklenen: Stable performance, no crashes
```
  
### 📈 **Performance Characteristics**

| Aspect | Complexity | Optimizations |
|--------|------------|---------------|
| **Pixel Computation** | O(width × height × iter) | Early bailout |
| **Zoom Operation** | O(1) | Mathematical transform only |
| **Color Mapping** | O(1) per pixel | Precomputed polynomials |
| **Memory Usage** | O(width × height) | Single image buffer |
| **Iteration Depth** | Adaptive (100-500) | Zoom-based adjustment |

### 🔍 **Optimization Techniques**

#### ⚡ **Computational Optimizations**

1. **Early Bailout**: Z magnitude kontrolü ile gereksiz iterasyonları önleme
2. **Adaptive Iterations**: Zoom seviyesine göre otomatik iteration ayarı
3. **Efficient Calculations**: `z² = (z.real)² - (z.imag)² + 2i(z.real)(z.imag)` optimized form
4. **Minimal Allocations**: Static buffers ve tek image allocation

#### 🎨 **Rendering Optimizations**

1. **Buffer Management**: Double buffering yerine tek buffer kullanımı
2. **Dirty Region Tracking**: Sadece değişen bölgeleri yeniden render (advanced)
3. **Color Cache**: Renk hesaplamalarını minimize etme
4. **MLX Optimization**: Efficient `mlx_put_image_to_window` kullanımı

---

## 📚 Notlar

### ⚠️ **Önemli Dikkat Edilmesi Gerekenler**

#### 🛡️ **Bellek Yönetimi**
- **MLX Images**: Her render'da image destroy/create gerekli (memory leak önleme)
- **Window Management**: Window close event'inde proper cleanup
- **Resource Cleanup**: ESC tuşu ve X button'da aynı cleanup path
- **Memory Leaks**: Valgrind ile sürekli kontrol

#### 🔧 **Platform Farkları**
- **Linux**: X11 libraries gerekli, `minilibx-linux` kullanımı
- **macOS**: OpenGL tabanlı, `minilibx-opengl` kullanımı
- **Key Codes**: Platform'a göre farklı key code tanımlamaları
- **Mouse Events**: Farklı button ID'leri (Linux: Button4/Button5, macOS: 4/5)

#### 🎨 **Görsel Kalite**
- **Smooth Coloring**: Logarithmic smoothing ile banding önleme
- **Color Palettes**: Bernstein polynomials ile smooth gradients
- **Iteration Depth**: Zoom ile adaptive ayarlama (100-500 range)
- **Edge Cases**: Set üyeleri için black, escape için colorful

### 💡 **Best Practices**

#### 🎯 **Code Quality:**
1. **Modularity**: Her fonksiyon tek responsibility
2. **Error Handling**: Her MLX call'da NULL check
3. **Input Validation**: Kullanıcı input'ları comprehensive validate
4. **Documentation**: Complex math için detailed comments
5. **Norminette**: 42 coding standards compliance

#### 🔍 **Debugging Tips:**
- **Visual Debug**: Iteration count'ları renk olarak gösterme
- **Parameter Testing**: Bilinen Julia parametreleri ile test
- **Zoom Limits**: Extreme zoom seviyelerinde test
- **Performance Profiling**: `time` command ile render speed ölçümü

### 📐 **Matematiksel Referanslar**

#### 🔢 **Fraktal Formülleri**

| Fraktal | Z₀ | Iterasyon | C |
|---------|-----|-----------|---|
| **Mandelbrot** | 0 | Zₙ₊₁ = Zₙ² + C | Pixel coordinate |
| **Julia** | Pixel coordinate | Zₙ₊₁ = Zₙ² + C | Sabit parametre |
| **Tricorn** | 0 | Zₙ₊₁ = conj(Zₙ)² + C | Pixel coordinate |
| **Celtic** | 0 | Zₙ₊₁ = \|Re(Zₙ²)\| + Im(Zₙ²)i + C | Pixel coordinate |

#### 🎨 **Renk Teorisi**
- **Escape Time**: İterasyon sayısına göre renklendirme
- **Smooth Coloring**: Logarithmic interpolation
- **Palette Design**: Bernstein basis functions
- **Visual Harmony**: Complementary color schemes

---

## 🏆 Proje Başarıları

<div align="center">

![Score](https://img.shields.io/badge/Score-125%2F100-gold?style=for-the-badge)
![Tests](https://img.shields.io/badge/Tests-All%20Passed-success?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen?style=for-the-badge)
![Bonus](https://img.shields.io/badge/Bonus-Completed-orange?style=for-the-badge)

### 📊 **Proje İstatistikleri**

| Metrik | Değer |
|--------|-------|
| **Source Files** | 16 (8 main + 8 bonus) |
| **Functions** | 30+ |
| **Fractal Types** | 4 (2main + 2 bonus) |
| **Lines of Code** | 1000+ |
| **Supported Platforms** | 2 (Linux + macOS) |
| **Color Schemes** | 10 |
| **Max Zoom Depth** | Iteration 500 |
| **Memory Leak Tests** | ✅ Valgrind Clean |

### 🎨 **Implemented Features**

| Feature | Status | Notes |
|---------|--------|-------|
| **Mandelbrot Set** | ✅ | Full implementation |
| **Julia Set** | ✅ | Parameter validation |
| **Mouse Zoom** | ✅ | Centered on cursor |
| **Keyboard Pan** | ✅ | Smooth movement |
| **Color Cycling** | ✅ | 10 palettes |
| **Smooth Coloring** | ✅ | Logarithmic |
| **Adaptive Iterations** | ✅ | 100-500 range |
| **Tricorn (Bonus)** | ✅ | Conjugate variation |
| **Celtic (Bonus)** | ✅ | Absolute value variation |
| **Cross-Platform** | ✅ | Linux + macOS |

</div>

---

<div align="center">

### 🎯 **Core Skills Gained**

![Graphics Programming](https://img.shields.io/badge/Graphics-Programming-blue?style=flat-square)
![Complex Math](https://img.shields.io/badge/Complex-Mathematics-green?style=flat-square)
![Event Handling](https://img.shields.io/badge/Event-Handling-orange?style=flat-square)
![Optimization](https://img.shields.io/badge/Performance-Optimization-red?style=flat-square)
![Fractal Geometry](https://img.shields.io/badge/Fractal-Geometry-purple?style=flat-square)

---

**🌀 "Fract-ol reveals that infinite complexity can emerge from simple mathematical rules."**

*Bu proje, matematik ve programlamanın buluştuğu noktada, sanatsal ve bilimsel düşünceyi birleştirir.*

---

### 👨‍💻 Created by Sude Naz Karayıldırım

[![42 Profile](https://img.shields.io/badge/42%20Profile-skarayil-black?style=flat-square&logo=42&logoColor=white)](https://profile.intra.42.fr/users/skarayil)
[![GitHub](https://img.shields.io/badge/GitHub-skarayil-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/skarayil)

**⭐ Eğer bu proje işinize yaradıysa, repo'ya star vermeyi unutmayın!**

</div>
