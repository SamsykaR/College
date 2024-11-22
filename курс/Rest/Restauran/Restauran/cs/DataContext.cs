using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;

namespace Restauran.cs
{
    internal class DataContext : DbContext
    {
        public DbSet<Food> Foods { get; set; }
        public DbSet<Order> Orders { get; set; }
        public DbSet<OrderedFood> OrderedFoods { get; set; }
        public DataContext() => Database.EnsureCreated();
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder) => optionsBuilder.UseSqlite(@"Data Source=..\DataBase.db");

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Food>().HasData(
                // Десерты
                new Food("Тирамису", "Сочетает кремовую маскарпоне с согревающим ароматом кофе и шоколада", 200) { NameType = "Десерт", IDFood = 1 },
                new Food("Желе", "Нежное желе из фруктового и ягодного сока", 100) { NameType = "Десерт", IDFood = 2 },
                new Food("Шоколадный торт", "Влажный пирог с насыщенным шоколадным вкусом", 300) { NameType = "Десерт", IDFood = 3 },
                new Food("Павлова", "Легкий безе с кремом и свежими фруктами", 250) { NameType = "Десерт", IDFood = 4 },
                new Food("Фруктовый салат", "Ассорти из свежих сезонных фруктов", 150) { NameType = "Десерт", IDFood = 5 },

                // Напитки
                new Food("Чай", "Чёрный чай из лепестков дуба", 50) { NameType = "Напиток", IDFood = 6 },
                new Food("Красное вино", "Выдержанное красное вино", 1000) { NameType = "Напиток", IDFood = 7 },
                new Food("Белое вино", "Легкое и освежающее белое вино", 950) { NameType = "Напиток", IDFood = 8 },
                new Food("Коктейль Мохито", "Освежающий коктейль с мятой и лаймом", 400) { NameType = "Напиток", IDFood = 9 },
                new Food("Кофе", "Ароматный кофе с нотками шоколада", 80) { NameType = "Напиток", IDFood = 10 },

                // Закуски высокой кухни
                new Food("Канапе с икрой", "Канапе с черной солью и нежной красной икрой", 250) { NameType = "Закуска высокой кухни", IDFood = 11 },
                new Food("Тартар из лосося", "Свежий лосось, мелко нарезанный с пряностями", 400) { NameType = "Закуска высокой кухни", IDFood = 12 },
                new Food("Фуа-гра", "Изысканная печень утки, подается с тостами", 1200) { NameType = "Закуска высокой кухни", IDFood = 13 },
                new Food("Устрицы", "Свежие устрицы с лимонным соком", 800) { NameType = "Закуска высокой кухни", IDFood = 14 },
                new Food("Креветки в чесночном соусе", "Сочные креветки в ароматном чесночном соусе", 650) { NameType = "Закуска высокой кухни", IDFood = 15 },

                // Основные блюда
                new Food("Стейк", "Сочный говяжий стейк, приготовленный до средней степени прожарки", 1500) { NameType = "Основное блюдо", IDFood = 16 },
                new Food("Лосось на гриле", "Запеченный лосось с лимоном и пряностями", 1200) { NameType = "Основное блюдо", IDFood = 17 },
                new Food("Паста с креветками", "Паста с нежными креветками и томатным соусом", 800) { NameType = "Основное блюдо", IDFood = 18 },
                new Food("Филе цыпленка", "Филе курицы с овощами на гриле", 700) { NameType = "Основное блюдо", IDFood = 19 },
                new Food("Вегетарианская пицца", "Пицца с свежими овощами и сырами", 600) { NameType = "Основное блюдо", IDFood = 20 },
                new Food("Говяжий бургер", "Сочный бургер с говядиной, свежими овощами и соусом", 900) { NameType = "Основное блюдо", IDFood = 21 },
                new Food("Цезарь с курицей", "Салат Цезарь с гриль-курицей и пармезаном", 500) { NameType = "Основное блюдо", IDFood = 22 },
                new Food("Ризотто с грибами", "Кремовое ризотто с лесными грибами и трюфельным маслом", 750) { NameType = "Основное блюдо", IDFood = 23 },
                new Food("Куриные крылышки", "Крылышки, запеченные в остром соусе", 450) { NameType = "Основное блюдо", IDFood = 24 },
                new Food("Паста альфредо", "Паста с кремовым соусом альфредо и пармезаном", 850) { NameType = "Основное блюдо", IDFood = 25 },
                new Food("Кебаб", "Нежные кусочки мяса, запеченные на шампуре", 1000) { NameType = "Основное блюдо", IDFood = 26 },
                new Food("Рыба на пару", "Нежная рыба, приготовленная на пару с лимоном и зеленью", 650) { NameType = "Основное блюдо", IDFood = 27 },
                new Food("Чили кон карне", "Острая мексиканская фасоль с мясом и специями", 800) { NameType = "Основное блюдо", IDFood = 28 },
                new Food("Лазанья", "Лазанья с мясом, сыром и томатным соусом", 950) { NameType = "Основное блюдо", IDFood = 29 },
                new Food("Запеченные овощи", "Ассорти запеченных сезонных овощей с травами", 500) { NameType = "Основное блюдо", IDFood = 30 },

                // Закуски
                new Food("Брускетта", "Гренка с помидорами и базиликом", 100) { NameType = "Закуска", IDFood = 31 },
                new Food("Сырная тарелка", "Ассорти из различных сыров с медом и орехами", 500) { NameType = "Закуска", IDFood = 32 },
                new Food("Овощи гриль", "Ассорти овощей, приготовленных на гриле", 300) { NameType = "Закуска", IDFood = 33 },
                new Food("Куриные крылышки", "Со spicy соусом", 450) { NameType = "Закуска", IDFood = 34 },
                new Food("Чипсы с соусом гуакамоле", "Кукурузные чипсы с нежным соусом", 200) { NameType = "Закуска", IDFood = 35 }
            );

            modelBuilder.Entity<Order>().HasData(
                new Order(300, DateTime.Now) { IDOrder = 1, IDWorker = 1 },
                new Order(450, DateTime.Now.AddMinutes(15)) { IDOrder = 2, IDWorker = 2 },
                new Order(200, DateTime.Now.AddMinutes(30)) { IDOrder = 3, IDWorker = 3 },
                new Order(500, DateTime.Now.AddMinutes(45)) { IDOrder = 4, IDWorker = 1 },
                new Order(350, DateTime.Now.AddMinutes(60)) { IDOrder = 5, IDWorker = 2 },
                new Order(400, DateTime.Now.AddMinutes(75)) { IDOrder = 6, IDWorker = 3 }, // Новый заказ
                new Order(600, DateTime.Now.AddMinutes(90)) { IDOrder = 7, IDWorker = 1 }  // Новый заказ
            );

            modelBuilder.Entity<OrderedFood>().HasData(
                new OrderedFood(1, 100) { IDOrderedFood = 1, IDFood = 3, IDOrder = 1 },  // Шоколадный торт
                new OrderedFood(2, 200) { IDOrderedFood = 2, IDFood = 5, IDOrder = 1 },  // Фруктовый салат
                new OrderedFood(3, 300) { IDOrderedFood = 3, IDFood = 11, IDOrder = 2 }, // Канапе с икрой
                new OrderedFood(4, 150) { IDOrderedFood = 4, IDFood = 12, IDOrder = 2 }, // Тартар из лосося
                new OrderedFood(5, 120) { IDOrderedFood = 5, IDFood = 7, IDOrder = 3 },  // Красное вино
                new OrderedFood(6, 100) { IDOrderedFood = 6, IDFood = 16, IDOrder = 4 }, // Стейк
                new OrderedFood(7, 80) { IDOrderedFood = 7, IDFood = 20, IDOrder = 5 },  // Вегетарианская пицца
                new OrderedFood(8, 60) { IDOrderedFood = 8, IDFood = 22, IDOrder = 5 },  // Сырная тарелка
                new OrderedFood(9, 250) { IDOrderedFood = 9, IDFood = 26, IDOrder = 6 }, // Кебаб
                new OrderedFood(10, 300) { IDOrderedFood = 10, IDFood = 29, IDOrder = 6 }, // Лазанья
                new OrderedFood(11, 200) { IDOrderedFood = 11, IDFood = 12, IDOrder = 7 }, // Тартар из лосося
                new OrderedFood(12, 150) { IDOrderedFood = 12, IDFood = 23, IDOrder = 7 }  // Ризотто с грибами
            );


        }
    }
}
