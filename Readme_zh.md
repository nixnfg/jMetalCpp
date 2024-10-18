# jMetalCpp 项目网站

jMetalCpp 是一个基于 C++ 的多目标优化框架。它是 [jMetal 项目](https://github.com/jmetal/jmetal) 的一个分支。

## 目录

0. 更新
1. 要求
2. 安装 jMetalCpp
3. 执行 jMetalCpp
4. 选择问题
5. 配置问题
6. 计算质量指标
7. 高级:构建实验
   7.1. 执行实验
   7.2. 从实验生成报告
8. 安装

### 0. 更新

版本 1.11:

* 添加了对 CMake 的支持,并成功在 MSCV 2019 的 Windows 上构建。贡献者:Dimitar Stanev ([https://github.com/mitkof6](https://github.com/mitkof6))

版本 1.10:

* 添加了新算法:飞蛾火焰优化算法 (MFO)。贡献者:Ahmad Dajani ([https://github.com/adajani](https://github.com/adajani))

版本 1.9:

* 添加了新算法:鲸鱼优化算法 (WOA)。贡献者:Ahmad Dajani ([https://github.com/adajani](https://github.com/adajani))

版本 1.8:

* 添加了新算法:GWO。贡献者:Ahmad Dajani ([https://github.com/adajani](https://github.com/adajani))
* 增强了带默认值的输入参数。

版本 1.7:

* 添加了新算法:MOCH
  预计不久将有新算法

版本 1.6:

* 添加了新算法:OMOPSO、PAES、SMPSOhv、StandardPSO2007 和 StandardPSO2011
* 添加了 CEC 2005 问题

版本 1.5:

* 添加了新算法:SMS-EMOA、ssNSGA-II、MOEA/D 和 CMA-ES。
* 添加了新问题:Srinivas、Tanaka、Rastrigin 和 Rosenbrock。
* 将 POSIX 线程改为 C++11 内置线程。

版本 1.0.1:

* 修复了导致最后一个 Wilcoxon 表无法正确生成的 bug。
* 将 FIT 质量指标改为最小化而不是最大化。

版本 1.0:

* 添加了质量指标。
* 添加了实验。

版本 0.1:

* 第一个版本。

### 1. 要求

jMetalCpp 已在 Unix 机器(Ubuntu 和 MacOS X)以及使用 Cygwin 的 Windows 上开发。使用 make 工具来编译软件包。

从 1.5 版本开始,必须使用支持 C++11 的 C++ 编译器。这是为了使用 C++11 线程库。

### 2. 安装 jMetalCpp

将压缩文件复制到要安装 jMetal 的位置,然后解压。

然后,使用以下命令编译代码:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% make</span></span></code></div></div></div></pre>

也可以使用 CMake 构建系统来独立于操作系统编译项目。以下是在 Linux 上构建的示例:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>mkdir build
</span></span><span>cd build
</span><span>cmake .. -DCMAKE_INSTALL_PREFIX=../install
</span><span>make</span></code></div></div></div></pre>

### 3. 执行 jMetal

所有主要的二进制文件都在 `bin` 文件夹中包含的 `main` 子文件夹中。进入此文件夹以执行 jMetal。

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% cd bin
</span></span><span>% cd main</span></code></div></div></div></pre>

此版本的 jMetal 提供了以下多目标元启发式算法:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">text</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code class="language-text" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>  算法                                   命令
</span></span><span>  ---------------------------------------------------------
</span><span>  NSGA-II                                     NSGAII_main
</span><span>  ssNSGA-II                                   ssNSGAII_main
</span><span>  GDE3                                        GDE3_main
</span><span>  SMPSO                                       SMPSO_main
</span><span>  SMPSOhv (新)                                SMPSOhv_main
</span><span>  OMOPSO (新)                                 OMOPSO_main
</span><span>  PAES (新)                                   PAES_main
</span><span>  SMS-EMOA                                    SMSEMOA_main
</span><span>  MOEA/D                                      MOEAD_main</span></code></div></div></div></pre>

此外,我们还包括这些技术的单目标变体:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">text</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code class="language-text" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>  算法                                   命令
</span></span><span>  ---------------------------------------------------------
</span><span>  DE (差分进化)                           DE_main
</span><span>  gGA (世代遗传算法)                      gGA_main
</span><span>  PSO (粒子群优化)                        PSO_main
</span><span>  PSO (标准 2007) (新)                    StandardPSO2007_main
</span><span>  PSO (标准 2011) (新)                    StandardPSO2011_main
</span><span>  ssGA (稳态遗传算法)                     ssGA_main
</span><span>  CMA-ES                                      CMAES_main
</span><span>  GWO (灰狼优化器)                         GWO_main
</span><span>  WOA (鲸鱼优化算法)                       WOA_main
</span><span>  MFO (飞蛾火焰优化算法)                   MFO_main</span></code></div></div></div></pre>

要执行一个元启发式算法,只需使用其关联的命令。例如,要执行 GDE3,只需输入以下命令:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./GDE3_main</span></span></code></div></div></div></pre>

### 4. 选择问题

如果像之前那样执行算法,每个算法都会使用默认问题。您可以通过将问题作为参数传递来指定要解决的问题。例如,如果您想执行世代遗传算法来解决 Sphere 问题,您需要执行以下命令:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./gGA_main Sphere</span></span></code></div></div></div></pre>

目前包含以下多目标问题:

* Fonseca
* Kursawe
* OneMax
* Schaffer
* Sphere
* Srinivas
* Tanaka
* DTLZ1
* DTLZ2
* DTLZ3
* DTLZ4
* DTLZ5
* DTLZ6
* DTLZ7
* ZDT1
* ZDT2
* ZDT3
* ZDT4
* ZDT5
* ZDT6
* LZ09_F1
* LZ09_F2
* LZ09_F3
* LZ09_F4
* LZ09_F5
* LZ09_F6
* LZ09_F7
* LZ09_F8
* LZ09_F9

当前单目标问题列表由以下组成:

* Griewank
* OneMax
* Rastrigin
* Rosenbrock
* Sphere
* CEC2005

### 5. 配置问题

当您选择要解决的问题时,可以通过将一些问题参数作为参数传递来配置它们。如果一个问题有三个参数,您可以选择指定其中的一个、两个或全部三个。

在解决问题时可以配置以下参数:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">text</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code class="language-text" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span> 问题           参数 1              参数 2                参数 3
</span></span><span>--------------------------------------------------------------------------------------
</span><span> Fonseca        解决方案类型
</span><span> Griewank       解决方案类型        变量数量
</span><span> Kursawe        解决方案类型        变量数量
</span><span> OneMax         位数               字符串数量
</span><span> Rastrigin      解决方案类型        变量数量
</span><span> Rosenbrock     解决方案类型        变量数量
</span><span> Shaffer        解决方案类型
</span><span> Sphere         解决方案类型        变量数量
</span><span> Srinivas       解决方案类型
</span><span> Tanaka         解决方案类型
</span><span> DTLZ1          解决方案类型        变量数量              目标数量
</span><span> DTLZ2          解决方案类型        变量数量              目标数量
</span><span> DTLZ3          解决方案类型        变量数量              目标数量
</span><span> DTLZ4          解决方案类型        变量数量              目标数量
</span><span> DTLZ5          解决方案类型        变量数量              目标数量
</span><span> DTLZ6          解决方案类型        变量数量              目标数量
</span><span> DTLZ7          解决方案类型        变量数量              目标数量
</span><span> LZ09_F1        解决方案类型
</span><span> LZ09_F2        解决方案类型
</span><span> LZ09_F3        解决方案类型
</span><span> LZ09_F4        解决方案类型
</span><span> LZ09_F5        解决方案类型
</span><span> LZ09_F6        解决方案类型
</span><span> LZ09_F7        解决方案类型
</span><span> LZ09_F8        解决方案类型
</span><span> LZ09_F9        解决方案类型
</span><span> ZDT1           解决方案类型        变量数量
</span><span> ZDT2           解决方案类型        变量数量
</span><span> ZDT3           解决方案类型        变量数量
</span><span> ZDT4           解决方案类型        变量数量
</span><span> ZDT5           解决方案类型        变量数量
</span><span> ZDT6           解决方案类型        变量数量</span></code></div></div></div></pre>

"解决方案类型"参数允许以下值:

- Real
- Binary

例如,如果您想使用 SMPSO 解决 DTLZ5 问题,并使用"Real"作为解决方案类型,您需要执行以下命令:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./SMPSO_main DTLZ5 Real</span></span></code></div></div></div></pre>

将来,将提供二进制-实数编码。

如果您打算修改 DTLZ5 问题的默认参数,使用十个变量和两个目标,必须执行以下命令:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>%./SMPSO_main DTLZ5 Real 10 2</span></span></code></div></div></div></pre>

CEC 2005 问题是一个例外,如果您设置一个、两个或三个参数,参数的顺序会发生变化。

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">text</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code class="language-text" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span> 问题           参数 1              参数 2                参数 3
</span></span><span>--------------------------------------------------------------------------------------
</span><span> CEC2005        问题编号
</span><span> CEC2005        解决方案类型        问题编号
</span><span> CEC2005        解决方案类型        问题编号              变量数量</span></code></div></div></div></pre>

<问题编号> 变量接受 1 到 25 的值。`解决方案类型` 和 `变量数量` 的默认值分别为 `Real` 和 10。
示例:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./gGA_main CEC2005 1
</span></span><span>% ./gGA_main CEC2005 Real 1
</span><span>% ./gGA_main CEC2005 Real 1 20</span></code></div></div></div></pre>

### 6. 计算质量指标

为了评估多目标元启发式算法的性能,需要质量指标来评估获得的帕累托前沿近似的质量。

此版本的 jMetal 提供了以下质量指标:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">text</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code class="language-text" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>  质量指标                             命令
</span></span><span>  ---------------------------------------------------------------------
</span><span>  超体积                               Hypervolume
</span><span>  分布                                 Spread
</span><span>  Epsilon                              Epsilon
</span><span>  世代距离                             GenerationalDistance
</span><span>  反向世代距离                         InvertedGenerationalDistance</span></code></div></div></div></pre>

这些质量指标需要知道问题的真实帕累托前沿。对于包含的基准问题,可以从 [http://jmetal.sourceforge.net/problems.html](http://jmetal.sourceforge.net/problems.html) 下载它们的帕累托前沿。

质量指标二进制文件包含在 `bin/qualityIndicator/main` 中。进入此文件夹以执行任何指标。

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% cd bin
</span></span><span>% cd qualityIndicator
</span><span>% cd main</span></code></div></div></div></pre>

要计算质量指标,您必须执行以下命令:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./<质量指标命令> <解决方案前沿文件> <真实前沿文件> <目标数量></span></span></code></div></div></div></pre>

例如,如果您需要计算元启发式算法在尝试解决 ZDT1 问题时获得的 FUN 文件上的超体积指标,您必须执行以下命令:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./Hypervolume /home/username/jmetalcpp-test/FUN /home/username/jmetalcpp-test/ZDT1.pf 2</span></span></code></div></div></div></pre>

请记住将文件路径更改为包含帕累托前沿的文件的实际位置。

### 7. 高级:构建实验

从这个版本的 jMetalCpp 开始,可以创建实验研究。实验由一系列算法组成,这些算法用于解决一系列问题,执行多次独立运行。然后通过应用质量指标来评估结果,并生成一组 Latex 文件和 R 脚本作为输出。这些文件包括包含平均值/中位数和标准差/四分位距的 Latex 表格,包括应用 Wilcoxon 秩和检验结果的 Latex 表格,以及包含箱线图的 eps 图形。

实验分为两个独立的部分:执行部分和报告部分。这种方法与 Java 版本的 jMetal 中使用的方法不同。当前 jMetalCpp 中包含的方法更灵活,包括更有效的并行方案,可以并行运行实验。

执行部分是使用选定的算法执行所有问题的部分。每个问题将被执行指定的次数。由于配置的数量可能很高,并且它们之间是独立的,因此算法可以由指定数量的线程并发执行,以利用当前的多核处理器。

报告部分允许应用质量指标来测量结果数据的质量,并计算统计信息,生成前面提到的 Latex 表格和图形。


## 7.1. 执行实验

要执行实验的"执行部分",您只需要执行相应的命令。这个版本的jMetalCpp提供了两个已经实现的实验,可以用作模板。随意编辑这些实验或创建新的实验。请记住,编辑代码后,您需要重新编译代码。

提供的两个实验是:

* `StandardStudyExecution`
* `StandardStudyExecutionSO`

第一个是多目标实验。第二个是单目标实验。要执行实验,您只需输入相应的命令。例如:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./StandardStudyExecution</span></span></code></div></div></div></pre>

在执行实验之前,重要的是要根据您的需求和系统配置更改代码中的一些参数。因此,您需要指示存储输出文件的当前路径以及从何处读取输入文件。您需要编辑位于'jmetalcpp/src/experiments/'文件夹中的相应.cpp文件。

在每个.cpp文件中,您可以指定以下参数:

* `experimentName`:
  顾名思义。它将用于创建存储结果的文件夹。
* `algorithmNameList`:
  实验中每个问题要执行的算法列表。
* `problemList`:
  实验中将要解决的问题列表。
* `independentRuns`:
  每个算法对每个问题执行的次数。
* `numberOfThreads`:
  用于并发执行算法的线程数。
* `experimentBaseDirectory`:
  存储所有实验结果的目录路径。在这个文件夹内,将创建以下结构:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">text</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code class="language-text" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>
</span></span><span>    - <experimentalBaseDirectory/experimentName>
</span><span>        |-data
</span><span>          |- <algorithm_1>
</span><span>          |	|- <problem_1>
</span><span>          |	|	使用算法1解决问题1的结果文件。
</span><span>          |	|	(FUN.1, FUN.2, ..., FUN.X, VAR.1, VAR.2, ..., VAR.X)
</span><span>          |	|- <problem_2>
</span><span>          |	|	使用算法1解决问题2的结果文件。
</span><span>          |	|	(FUN.1, FUN.2, ..., FUN.X, VAR.1, VAR.2, ..., VAR.X)
</span><span>          |	|- ...
</span><span>          |	|- <problem_n>
</span><span>          |   使用算法1解决问题n的结果文件。
</span><span>					|   (FUN.1, FUN.2, ..., FUN.X, VAR.1, VAR.2, ..., VAR.X)
</span><span>          |
</span><span>          |- <algorithm_2>
</span><span>          |	|- <problem_1>
</span><span>          |	|	使用算法2解决问题1的结果文件。
</span><span>          |	|- <problem_2>
</span><span>          |	|	使用算法2解决问题2的结果文件。
</span><span>          |	|- ...
</span><span>          |	|- <problem_n>
</span><span>          |		使用算法2解决问题n的结果文件。
</span><span>          |
</span><span>          |- ...
</span><span>          |
</span><span>          |- <algorithm_m>
</span><span>            |- <problem_1>
</span><span>            |	使用算法m解决问题1的结果文件。
</span><span>            |- <problem_2>
</span><span>            |	使用算法m解决问题2的结果文件。
</span><span>            |- ...
</span><span>            |- <problem_n>
</span><span>              使用算法m解决问题n的结果文件。</span></code></div></div></div></pre>

执行中使用的每个算法都必须正确配置。这在每个.cpp文件的algorithmSettings方法中完成。对于每个算法(NSGAII, GDE3, gGA...),这个版本的jMetalCpp提供了一个带有默认配置的Settings类。您可以编辑这些Setting类来更改算法参数。不要忘记编辑algorithmSettings以配置实验中使用的每个算法。可以在实验中多次执行相同的算法,但配置不同,但您需要为算法的每个变体实现不同的Settings类。

## 7.2. 从实验生成报告

要执行实验的"报告部分",您只需执行相应的命令。对于这部分,这个版本的jMetalCpp提供了三个已经实现的实验。前两个为多目标实验生成报告,第三个为单目标变体生成报告。如前所述,它们是模板,所以请根据您的需求自由编辑它们或从它们创建新的实验。请记住,编辑代码后,您需要重新编译代码。

提供的三个实验是:

* `StandardStudyReportPF`
* `StandardStudyReportRF`
* `StandardStudyReportSO`

Java版本jMetal中的实验假设您事先知道所解决问题的真实帕累托前沿,这个假设在 `StandardStudyReportPF`中考虑了(PF代表"帕累托前沿")。然而,如果帕累托前沿未知,就像在解决实际问题时通常发生的那样,那么方法就是从所有算法在每次独立运行中产生的所有解决方案前沿中获得参考帕累托前沿。`StandardStudyReportRF`(RF代表"参考前沿")被设计用来获取这些参考前沿,然后用于应用所需的质量指标。

`StandardStudyReportSO`为单目标实验生成报告。

要执行实验报告,您只需输入相应的命令。例如:

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs"></div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]" data-darkreader-inline-fill=""><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><code data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""><span><span>% ./StandardStudyReportPF</span></span></code></div></div></div></pre>

同样,在运行实验报告程序之前,必须正确配置它们。非常重要的是,以下列出的参数列表必须与之前运行的执行部分中包含的参数匹配:

* experimentName:
  顾名思义。它将用于知道从哪个文件夹读取执行结果。
* algorithmNameList:
  在实验执行部分中为每个问题执行的算法列表。
* problemList:
  在实验执行部分中解决的问题列表。
* independentRuns:
  在执行部分中每个算法对每个问题执行的次数。
* experimentBaseDirectory:
  存储所有实验结果的目录路径。
* indicatorList:
  将在报告中计算的质量指标列表。当进行单目标算法的实验时,唯一可能的值是 `FIT`。
* paretoFrontFile:
  将用于计算质量指标的最优帕累托前沿文件列表。仅当已知最优帕累托前沿且实验是关于多目标算法时才需要。
* paretoFrontDirectory:
  存储最优帕累托前沿的目录路径。仅在使用已知的最优帕累托前沿时才需要。如果是单目标实验,则不使用此参数。如果是多目标实验且未指定此参数,将生成参考帕累托前沿以计算质量指标。

如果执行StandardStudyReportRF程序,<experimentalBaseDirectory/experimentName/referenceFronts>目录将包含所解决问题的获得的参考前沿。

### 8. 安装

* 安装: make install
* 卸载: make uninstall
* 要安装到非 usr/local/ 目录,设置 PREFIX 的路径。例如 export PREFIX=a/b/c
