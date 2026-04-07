// CWG2915 - Explicit object parameters of type void
// { dg-do compile { target c++23 } }

struct A {
  void f (this void);                  // { dg-error "explicit object parameter cannot have .void. type" }
};

// After recovery, A::f is treated as a function with no parameters,
// so calling it via 'a.f()' must succeed.
void test (A a)
{
  a.f ();
}
