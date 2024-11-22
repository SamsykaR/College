using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualBasic.ApplicationServices;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory.Database;


namespace Restauran.cs
{
    public abstract class BaseConstruct
    {
        protected BaseConstruct() { }
    }
    public static class Enums
    {
        public static Dictionary<int, string> Types = new Dictionary<int, string> { 
            { 1, "Десерт" },
            { 2, "Напиток" },
            { 3, "Закуска высокой кухни" },
            { 4, "Основное блюдо" },
            { 5, "Закуска" }
        };

        public static Dictionary<int, Worker> Workers = new Dictionary<int, Worker> {
            {1, new Worker{Name = "Анатолий", LastName = "Чернов", FatherName = "Степанович" } },
            {2, new Worker{Name = "Мария", LastName = "Иванова", FatherName = "Петровна" } },
            {3, new Worker{Name = "Дмитрий", LastName = "Сидоров", FatherName = "Александрович" } }
        };
    }
    public class Food : BaseConstruct
    {

        [Key] public uint IDFood { get; set; }
        public string? NameF { get; set; }
        public string Description { get; set; }
        public uint Cost { get; set; }
        public string NameType { get; set; }
        public Food(string? Name, string Des, uint Cost)
        {
            NameF = Name;
            Description = Des;
            this.Cost = Cost;
        }
        public Food():base() { }
    }
    ////////////
    public class OrderedFood : BaseConstruct
    {
        [Key] public uint IDOrderedFood { get; set; }
        public short Count { get; set; }
        public uint Cost { get; set; }
        public uint IDFood { get; set; }
        [ForeignKey("IDFood")] public Food? Food { get; set; }
        public uint IDOrder { get; set; }
        [ForeignKey("IDOrder")] public Order? Order { get; set; }
        public OrderedFood(short Cou, uint Cos)
        {
            Count = Cou;
            Cost = Cos;
        }
        public OrderedFood():base() { }
    }
    //////////////////
    public class Order : BaseConstruct
    {
        [Key] public uint IDOrder { get; set; }
        public DateTime Date { get; set; }
        public uint Cost { get; set; }
        public List<OrderedFood> OrderedFoods { get; set; } = new();
        public uint IDWorker { get; set; }
        public Order(uint Cos, DateTime Date)
        {
            Cost = Cos;
            this.Date = Date;
        }
        public Order() : base() { }
    }
    //////////////////
    public class Worker
    {
        public String? Name { get; set; }
        public String? LastName { get; set; }
        public String? FatherName { get; set; }
    }
}
