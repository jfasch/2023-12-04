#include <map>
#include <string>
#include <iostream>
#include <thread>
#include <functional>
#include <memory>
#include <variant>

#include <chrono>
using namespace std::chrono_literals;

class UpwardsCounter
{
public:
    UpwardsCounter(int lo, int hi) : _lo(lo), _hi(hi) {}
    void operator()() {
        for (int i=_lo; i<=_hi; ++i) {
            std::cout << "UP " << i << std::endl;
            std::this_thread::sleep_for(1s);
        }
    }
private:
    int _lo, _hi;
};

void down_1000_to_980()
{
    for (int i=1000; i>=980; --i) {
        std::cout << "DOWN " << i << std::endl;
        std::this_thread::sleep_for(0.5s);
    }
}

class TodoList final
{
public:
    TodoList() = default;
    TodoList(std::initializer_list<std::pair<std::string, std::function<void()>>> l)
    {
        for (const auto& elem: l)
            _list.insert(elem);
    }

    TodoList(const TodoList&) = delete;
    TodoList& operator=(const TodoList&) = delete;

    void add(const std::string& name, std::function<void()> f)
    {
        _list[name] = f;
    }
    void start()
    {
        for (auto& [name, item]: _list) {
            std::cout << "starting " << name << '\n';
            auto func = std::get<std::function<void()>>(item);
            item = std::make_shared<std::thread>(func);
        }
    }
    void wait()
    {
        for (auto& [name, item]: _list) {
            std::cout << "waiting for " << name << '\n';
            auto th = std::get<std::shared_ptr<std::thread>>(item);
            th->join();
        }
    }

private:
    using todo_item = std::variant<std::function<void()>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string, todo_item>;

    todo_list _list;
};

int main()
{
    TodoList tdl{
        {"up 1 to 3",
         UpwardsCounter(1, 3)},
        {"up 4 to 6",
         [lo=4, hi=6]() { 
             for (int i=lo; i<=hi; ++i) {
                 std::cout << "eh " << i << std::endl;
             }
         }
        },
        { "down 1000 to 980",
          down_1000_to_980
        },
    };

    tdl.start();
    tdl.wait();

    return 0;
}
