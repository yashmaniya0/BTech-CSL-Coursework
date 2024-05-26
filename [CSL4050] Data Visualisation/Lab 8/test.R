library(shiny)
library(plotly)
library(ggplot2)
library(dplyr)

# Read the dataset
thyroid_data <- read.csv("new-thyroid.data", header = TRUE)

# Define UI
ui <- fluidPage(
  titlePanel("Thyroid Data Visualization"),
  sidebarLayout(
    sidebarPanel(
      selectInput("x_axis", "X-axis attribute:",
                  choices = names(thyroid_data[-1])),
      selectInput("y_axis", "Y-axis attribute:",
                  choices = names(thyroid_data[-1])),
      checkboxGroupInput("classes", "Select classes to show:",
                         choices = c("Normal" = 1, "Hyper" = 2, "Hypo" = 3),
                         selected = c(1, 2, 3)),
      selectInput("class1_color", "Normal color:", choices = c("Red", "Blue", "Green", "Orange", "Purple", "Yellow"), selected = "Red"),
      selectInput("class2_color", "Hyper color:", choices = c("Red", "Blue", "Green", "Orange", "Purple", "Yellow"), selected = "Blue"),
      selectInput("class3_color", "Hypo color:", choices = c("Red", "Blue", "Green", "Orange", "Purple", "Yellow"), selected = "Green"),
      sliderInput("point_size", "Point size:", min = 5, max = 15, value = 5),
      radioButtons("point_shape", "Point shape:",
                   choices = c("Circle", "Square", "Diamond"),
                   selected = "Circle")
    ),
    mainPanel(
      tabsetPanel(
        tabPanel("Scatter Plot", plotlyOutput("scatter_plot")),
        tabPanel("Violin/Box Plot", plotOutput("box_violin_plot"))
      )
    )
  )
)

# Define server logic
server <- function(input, output) {
  
  # Create Scatter Plot
  output$scatter_plot <- renderPlotly({
    filtered_data <- filter(thyroid_data, class %in% input$classes)
    
    # Define color vector based on selected colors for each class
    color_vector <- rep(input$class1_color, nrow(filtered_data))
    color_vector[filtered_data$class == 2] <- input$class2_color
    color_vector[filtered_data$class == 3] <- input$class3_color
    
    plot <- plot_ly(data = filtered_data, x = ~get(input$x_axis), y = ~get(input$y_axis), color = as.factor(filtered_data$class), colors = color_vector) %>%
      add_markers(size = input$point_size, symbol = input$point_shape, color = ~as.factor(filtered_data$class), marker = list(size = input$point_size)) %>%
      layout(xaxis = list(title = input$x_axis),
             yaxis = list(title = input$y_axis),
             legend = list(title = "Class", 
                           itemsizing = "constant", 
                           itemwidth = 30, 
                           itemclick = FALSE, 
                           itemdoubleclick = FALSE),
             colorway = c(input$class1_color, input$class2_color, input$class3_color)) %>%
      layout(legend = list(title = "Class",
                           items = list(
                             list(label = "Normal", method = "restyle", args = list("showlegend", c(TRUE, FALSE, FALSE))),
                             list(label = "Hyper", method = "restyle", args = list("showlegend", c(FALSE, TRUE, FALSE))),
                             list(label = "Hypo", method = "restyle", args = list("showlegend", c(FALSE, FALSE, TRUE)))
                           ))
      )
    plot <- plot %>% layout(dragmode = "zoom", hovermode = "closest")
    plot
  })
  
  # Create Violin/Box Plot
  output$box_violin_plot <- renderPlot({
    ggplot(data = thyroid_data) +
      geom_violin(aes(x = as.factor(class), y = get(input$y_axis), fill = as.factor(class)), trim = FALSE) +
      geom_boxplot(aes(x = as.factor(class), y = get(input$y_axis)), width = 0.1, fill = "white", color = "black", outlier.shape = NA) +
      labs(x = "Class", y = input$y_axis) +
      theme_minimal()
  })
}

# Run the application
shinyApp(ui = ui, server = server)
