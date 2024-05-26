library(shiny)
library(ggplot2)

wine_data <- read.csv("WineQT.csv")

ui <- fluidPage(
  titlePanel("Interactive Box Plot"),
  sidebarLayout(
    sidebarPanel(
      sliderInput("quality", "Minimum wine quality:", min = 3, max = 9, value = 5)
    ),
    mainPanel(
      plotOutput("boxplot")
    )
  )
)

server <- function(input, output) {
  output$boxplot <- renderPlot({
    filtered_data <- subset(wine_data, quality >= input$quality)
    ggplot(filtered_data, aes(x = factor(quality), y = alcohol)) +
      geom_boxplot() +
      labs(title = "Boxplot of Alcohol content by Wine Quality", x = "Quality", y = "Alcohol Content")
  })
}

shinyApp(ui = ui, server = server)
