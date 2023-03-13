# BAITAP_EMBEDDED

- Trong 2 ngày học C++ nâng cao, anh Hiếu đã dạy những kiến thức về OOP bao gồm: 
    + Class là gì? Cách khai báo class?
    + Các thành phần có trong class
    + Constructor
    + Phạm vi truy cập: public và private
    + Các tính chất có trong OOP

- Sau khi học xong thì em hiểu được những phần như sau:

  + Class là kiểu dữ liệu do người dùng tự định nghĩa.
  + Class gần giống với struct. Khác ở chỗ các member strong struct là các biến còn trong class được gọi là các property.
  + Trong class có thể khai báo các hàm còn được gọi với tên khác là method, còn trong struct thì không.
  + Constructor là một phương thức đặc biệt, sẽ được tự động gọi tới khi khai báo 1 object.
  + Phương thức constructor không có kiểu trả về và tên của nó trùng với tên của class
  + Constructor có 2 loại là constructor có tham số và constructor không có tham số.
  + Nếu không khai báo constructor thì class sẽ tự động tạo ra constructor mặc định (constructor không có tham số).
  + Nếu trong class đã khai báo constructor thì class sẽ không tự tạo constructor mặc định. Nếu khai báo 1 object khác với constructor đã được khai báo trong class sẽ báo lỗi
  + Phạm vi truy cập public cho phép các object tự do truy cập vào các property trong public.
  + Phạm vi truy cập private sẽ không cho các object truy cập vào nó mà các property được khai báo trong private chỉ được truy cập bên trong class.
  + Các tính chất trong OOP:
    --Tính đóng gói (Encapsulation):
        -+Tính đóng gói có ý nghĩa không cho phép người sử dụng cái object có thể thay đổi các trạng thái nội tại của đối tượng, mà chỉ có thể thay đổi thông qua                 method
        -+Khi thay đổi thông qua method, chúng ta có thể kiểm soát giá trị thay đổi 
    --Tính kế thừa (Inheritance):
        >> Một class có thể kế thừa các thuộc tính của 1 class khác.
        >> Class kế thừa thuộc tính được gọi là class con (subclass), Class được kế thừa gọi là class cha (superClass)
        >> Các property hoặc method nằm trong phạm vi private sẽ không được kế thừa ở class con.
        >> Constructor của class con sẽ luôn được gọi tới class cha. Nếu constructor ở class con không chỉ rõ cần gọi tới Constructor nào của class cha thì class con              sẽ luôn gọi tới Constructor mặc định của class cha.
        >> Khi khai báo method ở class con trùng với method được khai báo ở class cha thì method ở class con sẽ ghi đè method ở class cha.
     >Tính đa hình (Polymorphism):
        >> Tính đa hình cho phép trong cùng 1 class có thể đưa ra nhiều method có cùng tên nhưng khác nhau về các input parameter hoặc kiểu dữ liệu trả về
     > Tính trừu tượng (Abstraction) (Em chưa hiểu cách thực hiện tính chất này):
        >> Tính chất này giúp bỏ qua sự phức tạp bên trong method mà chỉ quan tâm đến kết quả đạt được.
      
