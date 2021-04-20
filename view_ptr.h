#ifndef VIEW_PTR_H
#define VIEW_PTR_H

template<typename T>
class view_ptr final {
	public:

		constexpr inline view_ptr() noexcept :
			ptr_(nullptr)
		{
			
		}

		constexpr inline explicit view_ptr(std::nullptr_t) noexcept :
			ptr_(nullptr)
		{

		}
	
		constexpr inline explicit view_ptr(T* ptr) noexcept :
			ptr_(ptr)
		{
			
		}

		inline ~view_ptr() noexcept {
			release();
		}

		constexpr view_ptr(const view_ptr& other) noexcept :
			ptr_(other.get())
		{
			
		}

		constexpr inline view_ptr& operator =(const view_ptr& other) noexcept {
			ptr_ = other.get();
			return *this;
		}

		constexpr inline view_ptr& operator =(std::nullptr_t) noexcept {
			ptr_ = nullptr;
			return *this;
		}

		constexpr view_ptr(view_ptr&& other) noexcept :
			ptr_(other)
		{
			
		}

		constexpr inline view_ptr& operator =(view_ptr&& other) noexcept {
			ptr_ = other.get();
			return *this;
		}

		constexpr inline T& operator *() const noexcept {
			return *ptr_;
		}

		constexpr inline T* operator ->() const noexcept {
			return ptr_;
		}

		constexpr inline T* get() const noexcept {
			return ptr_;
		}

		constexpr inline explicit operator bool() const noexcept {
			return ptr_ != nullptr;
		}

		constexpr inline explicit operator T*() const noexcept {
			return ptr_;
		}

		constexpr inline explicit operator const T*() const noexcept {
			return ptr_;
		}

		constexpr inline void release() noexcept {
			ptr_ = nullptr;
		}

	private:
		T* ptr_;
	
};


#endif
