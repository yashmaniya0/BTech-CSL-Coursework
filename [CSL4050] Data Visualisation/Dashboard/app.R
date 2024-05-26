# Install and load necessary packages
library(shiny)
library(shinydashboard)
library(plotly)
library(dplyr)
library(ggridges)

# Load the dataset
data <- read.csv("./customer_shopping_data.csv")

# Define UI
ui <- dashboardPage(
  dashboardHeader(title = "Sale Analytics Dashboard"),
  dashboardSidebar(
    sidebarMenu(
      menuItem("Dashboard", tabName = "dashboard", icon = icon("dashboard")),
      menuItem("Overall Sales Analysis", tabName = "sales_analysis", icon = icon("chart-bar"),
               menuSubItem("Monthly Sales", tabName = "sales_analysis"),
               menuSubItem("Sales by Location", tabName = "sales_analysis")),
      menuItem("Category Wise Sales", tabName = "total_sales", icon = icon("dollar-sign")),
      menuItem("Gender & Age Sales Analysis", tabName = "gender_age_sales", icon = icon("users")),
      menuItem("Payment Method Analysis", tabName = "payment_method_analysis", icon = icon("credit-card"))
    )
  ),
  dashboardBody(
    tabItems(
      tabItem(tabName = "dashboard",
              h2("Shopping Mall Sales - Istanbul, Turkey",  style = "text-align: center;"),
              fluidRow(
                column(12, 
                       tags$div(
                         style = "text-align: center; margin-left: -2%; margin-bottom: 2%;",
                         tags$img(src = "https://www.lystloc.com/blog/wp-content/uploads/2023/05/A-Brief-Knowledge-On-Sales-Analysis-How-To-Perform-An-Effective-Sales-Analysis.webp", 
                                  height = "370px")
                       )
                       
                ),
                tags$style(
                  ".center {
                     display: flex;
                     justify-content: center;
                  }
                  .box-wrapper {
                     width: 60%; /* Adjust width here */
                     margin: 0 auto;
                  }"
                ),
                fluidRow(
                  column(12,
                         div(class = "center",
                             tags$style(".col-md-6 a { color: white; transition: font-size 0.2s; }
                              .col-md-6 a:hover { font-size: 1.2em; color: cyan}"),
                             div(
                               class = "container-fluid box-wrapper",
                               div(
                                 class = "row",
                                 div(
                                   class = "col-md-6",
                                   box(title = "Overall Sales Analysis", background = "green", width = 11, height = 100, menuItem("View", tabName = "sales_analysis", icon = icon("chart-bar")), solidHeader = TRUE)
                                 ),
                                 div(
                                   class = "col-md-6",
                                   box(title = "Total Sales & Category Wise Sales", width = 11, height = 100, background = "yellow", menuItem("View", tabName = "total_sales", icon = icon("chart-bar")), solidHeader = TRUE)
                                 ),
                               )
                             )
                         )
                  )
                ),
                fluidRow(
                  column(12,
                         div(class = "center",
                             div(
                               class = "container-fluid box-wrapper",
                               div(
                                 class = "row",
                                 div(
                                   class = "col-md-6",
                                   box(title = "Sales Analysis by Gender and Age", width = 11, height = 100, background = "blue", menuItem("View", tabName = "gender_age_sales", icon = icon("chart-bar")), solidHeader = TRUE)
                                 ),
                                 div(
                                   class = "col-md-6",
                                   box(title = "Payment Method Analysis", width = 11, height = 100, background = "orange", menuItem("View", tabName = "payment_method_analysis", icon = icon("chart-bar")), solidHeader = TRUE)
                                 )
                               )
                             )
                         )
                  )
                )
              )
      ),
      tabItem(tabName = "total_sales",
              h2("Total Sales & Category Wise Sales", style = "text-align: center; margin-bottom: 50px"),
              fluidRow(
                column(4, valueBoxOutput("total_sales_value"), height = "400px"),
                column(7, plotlyOutput("category_sales_plot", height = "500px"))
              )
      ),
      tabItem(tabName = "sales_analysis",
              h2("Monthly Sales & Sales by Location",  style = "text-align: center; margin-bottom: 50px"),
              fluidRow(
                column(6, plotlyOutput("monthly_sales_plot", height = "400px")),
                column(6, plotlyOutput("location_sales_plot", height = "400px"))
              )
      ),
      tabItem(tabName = "gender_age_sales",
              h2("Sales Analysis by Gender and Age", style = "text-align: center; margin-bottom: 30px"),
              fluidRow(
                column(10, offset = 1, 
                       tabsetPanel(
                         tabPanel("Sales Distribution by Gender", 
                                  plotlyOutput("gender_age_sales_plot", height = "550px")
                         ),
                         tabPanel("Sales Distribution by Age", 
                                  plotlyOutput("sales_distribution_plot", height = "550px")
                         )
                       )
                )
              )
      ),
      tabItem(tabName = "payment_method_analysis",
              h2("Payment Method Analysis",  style = "text-align: center; margin-bottom: 50px"),
              fluidRow(
                column(6, plotlyOutput("payment_method_bar_plot", height = "400px")),
                column(6, plotlyOutput("payment_method_pie_plot", height = "400px"))
              )
      )
    )
  )
)



# Define server logic
server <- function(input, output, session) {
  
  # Navigate to Total Sales tab on clicking the button
  observeEvent(input$total_sales_btn, {
    updateTabItems(session, "sidebarMenu", "total_sales")
  })
  
  # Navigate to Monthly Sales tab on clicking the button
  observeEvent(input$monthly_sales_btn, {
    updateTabItems(session, "sidebarMenu", "sales_analysis")
  })
  
  # Navigate to Sales by Location tab on clicking the button
  observeEvent(input$location_sales_btn, {
    updateTabItems(session, "sidebarMenu", "sales_analysis")
  })
  
  # Navigate to Gender & Age Sales tab on clicking the button
  observeEvent(input$gender_age_sales_btn, {
    updateTabItems(session, "sidebarMenu", "gender_age_sales")
  })
  
  # Navigate to Payment Method Analysis tab on clicking the button
  observeEvent(input$payment_method_analysis_btn, {
    updateTabItems(session, "sidebarMenu", "payment_method_analysis")
  })
  
  # Calculate total sales value
  output$total_sales_value <- renderUI({
    total_sales <- sum(data$quantity * data$price)
    
    div(
      style = "background-color: #426CA8; color: white; padding-top: 50px; text-align: center; 
    font-size: 3rem; width: 400px; height: 200px; margin: auto;",
      strong("Total Sales"),
      br(),
      format(total_sales, big.mark = ",", scientific = FALSE),
      icon("dollar-sign", lib = "font-awesome"),
    )
  })
  
  
  
  # Generate Category Wise Sales pie chart
  output$category_sales_plot <- renderPlotly({
    category_sales <- data %>% 
      group_by(category) %>%
      summarise(total_sales = sum(price)) %>%
      arrange(desc(total_sales))
    
    # Calculate percentage of total sales for each category
    category_sales <- category_sales %>%
      mutate(percent = total_sales / sum(total_sales) * 100)
    
    # Combine smaller categories into 'Others' if their percentage is less than 1%
    category_sales <- category_sales %>%
      mutate(category = ifelse(percent < 1, "Others", category)) %>%
      group_by(category) %>%
      summarise(total_sales = sum(total_sales))
    
    # Generate pie chart
    plot_ly(
      labels = category_sales$category,
      values = category_sales$total_sales,
      type = 'pie',
      textposition = 'inside',
      textinfo = 'percent+label'
    ) %>%
      layout(title = "Category-wise Sales", margin = list(l = 50, r = 50, t = 50, b = 50))
  })
  
  # Generate Monthly Sales plot
  output$monthly_sales_plot <- renderPlotly({
    data$invoice_date <- as.Date(data$invoice_date, "%m/%d/%Y")
    data$month <- format(data$invoice_date, "%b")
    
    monthly_sales <- data %>% 
      group_by(month) %>% 
      summarise(total_sales = sum(quantity * price))
    
    plot_ly(monthly_sales, x = ~month, y = ~total_sales, type = "bar", marker = list(color = "skyblue")) %>%
      layout(xaxis = list(title = "Month"), yaxis = list(title = "Sales"), title = "Monthly Sales", margin = list(l = 50, r = 50, t = 50, b = 50))
  })
  
  # Generate Sales by Location plot
  output$location_sales_plot <- renderPlotly({
    location_sales <- data %>% 
      group_by(shopping_mall) %>% 
      summarise(total_sales = sum(quantity * price))
    
    plot_ly(location_sales, x = ~shopping_mall, y = ~total_sales, type = "bar", marker = list(color = "lightgreen"), hoverinfo = ~paste(shopping_mall, ": ", scales::dollar(total_sales))) %>%
      layout(xaxis = list(title = "Shopping Mall"), yaxis = list(title = "Sales"), title = "Sales by Location", margin = list(l = 50, r = 50, t = 50, b = 50))
  })
  
  # Generate Sales Distribution plot by Age and Gender
  output$sales_distribution_plot <- renderPlotly({
    # Create age groups
    age_groups <- cut(data$age, breaks = c(18, seq(20, 65, by = 5), 69), include.lowest = TRUE)
    
    # Group by age groups and gender, and calculate total sales
    age_gender_sales <- data %>% 
      mutate(age_group = age_groups) %>%
      group_by(age_group, gender) %>% 
      summarise(total_sales = sum(quantity * price))
    
    plot_ly(age_gender_sales, x = ~age_group, y = ~total_sales, color = ~gender, type = "bar") %>%
      layout(xaxis = list(title = "Age Groups"), yaxis = list(title = "Sales"), title = "Sales Distribution by Age", barmode = "group", margin = list(l = 50, r = 50, t = 50, b = 50))
  })
  
  
  
  
  # Generate Sales Analysis by Gender
  output$gender_age_sales_plot <- renderPlotly({
    gender_age_sales <- data %>% 
      group_by(gender, age) %>% 
      summarise(total_sales = sum(quantity * price))
    
    # Generate violin plot
    violin <- gender_age_sales %>%
      plot_ly(x = ~gender, y = ~total_sales, type = "violin", box = list(visible = TRUE), points = "all") %>%
      add_markers(alpha = 0.5) %>%
      layout(xaxis = list(title = "Gender"), yaxis = list(title = "Sales"), title = "Sales by Gender", margin = list(l = 50, r = 50, t = 50, b = 50))
    
    violin
  })
  
  # Generate Payment Method Bar Plot
  output$payment_method_bar_plot <- renderPlotly({
    payment_method_sales <- data %>%
      group_by(payment_method) %>%
      summarise(total_sales = sum(price * quantity))
    
    plot_ly(payment_method_sales, x = ~payment_method, y = ~total_sales, type = "bar", color = ~payment_method) %>%
      layout(xaxis = list(title = "Payment Method"), yaxis = list(title = "Sales"), title = "Sales vs Payment Method", margin = list(l = 50, r = 50, t = 50, b = 50))
  })
  
  # Generate Payment Method Pie Plot
  output$payment_method_pie_plot <- renderPlotly({
    payment_method_sales <- data %>%
      group_by(payment_method) %>%
      summarise(total_sales = sum(price * quantity))
    
    plot_ly(payment_method_sales, labels = ~payment_method, values = ~total_sales, type = "pie") %>%
      layout(title = "Payment Method Proportions", margin = list(l = 50, r = 50, t = 50, b = 50))
  })
}

# Run the application
shinyApp(ui = ui, server = server)
